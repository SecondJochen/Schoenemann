#include "attacks.h"

Bitboard generateKingAttacks(Bitboard& bitboard)
{
    Bitboard attacks;
    for (int i = 0; i < 64; i++)
    {
        // Placeholder later this should only be a copy of a bitboard of the current square
        Bitboard temp = bitboard;
        attacks |= shift<Direction::NORTH()>(temp);
    }
    return attacks;
}
