#ifndef SEE_O_H
#define SEE_O_H

#include "chess.hpp"
using namespace chess;

class SEE {
public:
    bool see(const Board &board, const Move &move, int &cutoff);
private:
    int getPieceValue(const Board &board, const Move &move);
    int getLeastValuableAttacker();
};


#endif //SEE_O_H
