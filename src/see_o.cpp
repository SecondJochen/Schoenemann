#include "see_o.h"
#include "tune.h"

bool SEE::see(const Board &board, const Move &move, int cutoff) {

    int score = getPieceValue(board, move) - cutoff;
    if (score < 0) {
        return false;
    }

    PieceType next = move.typeOf() == Move::PROMOTION ? move.promotionType() : board.at<PieceType>(move.from());
    score -= *SEE_PIECE_VALUES[next];

    if (score >= 0) {
        return true;
    }

    // Our side is the opposite of the current side to move
    // since we make a move we must revert the side to move
    Color side = ~board.sideToMove();

     Square toSquare = move.to();

    // In our occupied bitboard we make the move so we turn off the 'from' bit
    // and turn on the 'to' bit
    Bitboard occ = board.occ() ^ 1ULL << move.from().index() ^ 1ULL << move.to().index();

    const Bitboard queens = board.pieces(PieceType::QUEEN);
    const Bitboard bishops = queens | board.pieces(PieceType::BISHOP);
    const Bitboard rooks = queens | board.pieces(PieceType::ROOK);

    // We get every piece on the board and generate there attacks on the target square.
    // Then we do a bitwise and to only get the attacks on the target square
    Bitboard attackers;
    attackers |= board.pieces(PieceType::PAWN, Color::WHITE) & attacks::pawn(Color::WHITE, toSquare);
    attackers |= board.pieces(PieceType::PAWN, Color::BLACK) & attacks::pawn(Color::BLACK, toSquare);
    attackers |= bishops & attacks::bishop(toSquare, occ);
    attackers |= board.pieces(PieceType::KNIGHT) & attacks::knight(toSquare);
    attackers |= rooks & attacks::rook(toSquare, occ);
    attackers |= board.pieces(PieceType::QUEEN) & attacks::queen(toSquare, occ);
    attackers |= board.pieces(PieceType::KING) & attacks::king(toSquare);

    while (true) {

        // We make a copy of the attack bitboard with only our pieces
        Bitboard ourAttackers = attackers & board.us(side);

        // If we don't have any pieces on the board we finished the SEE loop
        // since one side has no more attackers on the square
        if (ourAttackers == 0) {
            break;
        }

        next = getLeastValuableAttacker(board, attackers, ourAttackers, side);

        if (next == PieceType::PAWN || next == PieceType::BISHOP || next == PieceType::QUEEN) {
            attackers |= attacks::bishop(toSquare, occ) & bishops;
        }
        std::cout << ourAttackers << std::endl;

        if (next == PieceType::ROOK || next == PieceType::QUEEN) {
            attackers |= attacks::rook(toSquare, occ) & rooks;
        }

        attackers &= occ;
        score = -score - 1 - *SEE_PIECE_VALUES[next];
        side = ~side;

        if (score >= 0) {
            // If our only attacker is our king, but the opponent still has defenders
            if (next == PieceType::KING && attackers & board.us(side)) {
                side = ~side;
            }
            break;
        }
    }

    return side != board.sideToMove();
}

int SEE::getPieceValue(const Board &board, const Move &move) {

    const std::uint16_t moveType = move.typeOf();

    // If the move is castling we return nothing because two pieces where moved
    if (moveType == Move::CASTLING) {
        return 0;
    }

    // If the move is en passant we know that the piece is a pawn
    if (moveType == Move::ENPASSANT) {
        return *SEE_PIECE_VALUES[static_cast<int>(PieceType::PAWN)];
    }

    // Get our score for the moved piece
    int score = *SEE_PIECE_VALUES[board.at<PieceType>(move.to())];

    // If the move is a promotion we want to add the promoted piece
    // minus a pawn which got promoted
    if (moveType == Move::PROMOTION) {
        score += *SEE_PIECE_VALUES[move.promotionType()] - *SEE_PIECE_VALUES[static_cast<int>(PieceType::PAWN)];
    }

    return score;
}

PieceType SEE::getLeastValuableAttacker(const Board &board, const Bitboard &attackers, Bitboard &occ, const Color color) {
    for (int piece = 0; piece < 6; piece++) {
        if (const Bitboard pieceAttack = attackers & board.pieces(static_cast<PieceType>(piece), color)) {
            occ ^= 1ULL << pieceAttack.lsb();
            return static_cast<PieceType>(piece);
        }
    }

    // If no attacker is found we return an empty piece
    return PieceType::NONE;
}
