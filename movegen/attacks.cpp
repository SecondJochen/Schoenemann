#include "attacks.h"

Bitboard generateKingAttacks(Bitboard& bitboard)
{
    Bitboard attacks;
    for (int i = 0; i < 64; i++)
    {
        Bitboard temp = bitboard.getFromSquare(i);
        attacks |= shift<Direction::NORTH()>(temp);
        attacks |= shift<Direction::SOUTH()>(temp);
        attacks |= shift<Direction::EAST()>(temp);
        attacks |= shift<Direction::WEST()>(temp);
        attacks |= shift<Direction::NORTH_EAST()>(temp);
        attacks |= shift<Direction::NORTH_WEST()>(temp);
        attacks |= shift<Direction::SOUTH_EAST()>(temp);
        attacks |= shift<Direction::SOUTH_WEST()>(temp);
    }
    return attacks;
}
