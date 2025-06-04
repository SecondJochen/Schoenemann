#ifndef SEE_O_H
#define SEE_O_H

#include "chess.hpp"
using namespace chess;

class SEE {
public:
    static bool see(const Board &board, const Move &move, int cutoff);
private:
    static int getPieceValue(const Board &board, const Move &move);
    static PieceType getLeastValuableAttacker(const Board &board, const Bitboard &attackers, Color color);
};


#endif //SEE_O_H
