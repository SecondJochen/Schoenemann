#include "see_o.h"
#include "tune.h"

bool SEE::see(const Board &board, const Move &move, int &cutoff) {
    return 0;
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
