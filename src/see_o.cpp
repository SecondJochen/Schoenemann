#include "see_o.h"
#include "tune.h"

bool SEE::see(const Board &board, const Move &move, int cutoff) {

    // Our side is the opposite of the current side to move
    // since we make a move we must revert the side to move
    Color ourSide = ~board.sideToMove();

    // We create a bitboards for all sliding pieces to save computation later on
    Bitboard bishop = board.pieces(PieceType::BISHOP);
    Bitboard rooks = board.pieces(PieceType::ROOK);
    Bitboard queens = board.pieces(PieceType::QUEEN);

    const Square toSquare = move.to();
    const Bitboard occ = board.occ();
    Bitboard attackers;
    attackers |= board.pieces(PieceType::PAWN, Color::WHITE) & attacks::pawn(Color::WHITE, toSquare);
    attackers |= board.pieces(PieceType::PAWN, Color::BLACK) & attacks::pawn(Color::BLACK, toSquare);
    attackers |= board.pieces(PieceType::BISHOP) & attacks::bishop(toSquare, occ);
    std::cout << attackers << std::endl;
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

PieceType SEE::getLeastValuableAttacker(const Board &board, const Bitboard &attackers, const Square &toSquare) {

}
