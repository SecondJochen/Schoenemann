//
// Created by thomas on 02.06.2025.
//

#include "see_o.h"

#include "tune.h"

int SEE::getPieceValue(const Board &board, const Move &move) {
    if (move.typeOf() == Move::ENPASSANT) {
        return *SEE_PIECE_VALUES[static_cast<int>(PieceType::PAWN)];
    }
}
