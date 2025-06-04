#include "see_o.h"
#include "tune.h"

bool SEE::see(const Board &board, const Move &move, int cutoff) {

    // Our side is the opposite of the current side to move
    // since we make a move we must revert the side to move
    Color ourSide = ~board.sideToMove();

    const Square toSquare = move.to();

    // In our occupied bitboard we make the move so we turn off the 'from' bit
    // and turn on the 'to' bit
    const Bitboard occ = board.occ() ^ 1ULL << move.from().index() ^ 1ULL << move.to().index();


    // We get every piece on the board and generate there attacks on the target square.
    // Then we do a bitwise and to only get the attacks on the target square
    Bitboard attackers;
    attackers |= board.pieces(PieceType::PAWN, Color::WHITE) & attacks::pawn(Color::WHITE, toSquare);
    attackers |= board.pieces(PieceType::PAWN, Color::BLACK) & attacks::pawn(Color::BLACK, toSquare);
    attackers |= board.pieces(PieceType::BISHOP) & attacks::bishop(toSquare, occ);
    attackers |= board.pieces(PieceType::KNIGHT) & attacks::knight(toSquare);
    attackers |= board.pieces(PieceType::ROOK) & attacks::rook(toSquare, occ);
    attackers |= board.pieces(PieceType::QUEEN) & attacks::queen(toSquare, occ);
    attackers |= board.pieces(PieceType::KING) & attacks::king(toSquare);
    std::cout << getLeastValuableAttacker(board, attackers, board.sideToMove()) << std::endl;
    return ourSide != board.sideToMove();
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

PieceType SEE::getLeastValuableAttacker(const Board &board, const Bitboard &attackers, const Color color) {
    for (int piece = 0; piece <= 5; piece++) {
        if (Bitboard bitboard = attackers & board.pieces(static_cast<PieceType>(piece), color);
            bitboard.getBits() > 0) {
            //occ ^= (1ULL << bitboard.lsb());
            return static_cast<PieceType>(piece);
            }
    }

    // If no attacker is found we return an empty piece
    return PieceType::NONE;
}
