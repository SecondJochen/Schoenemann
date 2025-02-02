#include "attacks.h"

Bitboard generateKingAttacks(Bitboard& bitboard)
{
    Bitboard attacks;
    for (int i = 0; i < 64; i++)
    {
        Bitboard temp = bitboard.getFromSquare(i);
        attacks |= shift<Direction::NORTH>(temp);
        attacks |= shift<Direction::SOUTH>(temp);
        attacks |= shift<Direction::EAST>(temp);
        attacks |= shift<Direction::WEST>(temp);
        attacks |= shift<Direction::NORTH_EAST>(temp);
        attacks |= shift<Direction::NORTH_WEST>(temp);
        attacks |= shift<Direction::SOUTH_EAST>(temp);
        attacks |= shift<Direction::SOUTH_WEST>(temp);
    }
    return attacks;
}

Bitboard generateKnighAttacks(Bitboard &bitboard)
{
    Bitboard attacks;
    for (int i = 0; i < 64; i++)
    {
        Bitboard temp = bitboard.getFromSquare(i);
        attacks |= shift<Direction::EAST>(shift<Direction::NORTH_EAST>(temp));
        attacks |= shift<Direction::WEST>(shift<Direction::NORTH_WEST>(temp));
        attacks |= shift<Direction::EAST>(shift<Direction::SOUTH_EAST>(temp));
        attacks |= shift<Direction::WEST>(shift<Direction::SOUTH_WEST>(temp));
        attacks |= shift<Direction::EAST>(shift<Direction::NORTH_EAST>(temp));
        attacks |= shift<Direction::NORTH>(shift<Direction::NORTH_EAST>(temp));
        attacks |= shift<Direction::NORTH>(shift<Direction::NORTH_WEST>(temp));
        attacks |= shift<Direction::SOUTH>(shift<Direction::SOUTH_EAST>(temp));
        attacks |= shift<Direction::SOUTH>(shift<Direction::SOUTH_WEST>(temp));
    }
    return attacks;
}

Bitboard generateRockAttacks(Bitboard &occupied, std::uint8_t square)
{
    Bitboard attacks;
    Bitboard squareBitboard = occupied.getFromSquare(square);
    while (squareBitboard)
    {
        attacks |= squareBitboard;
        if (occupied & squareBitboard)
        {
            break;
        }
        squareBitboard = shift<Direction::NORTH>(squareBitboard);
    }

    attacks &= squareBitboard.getBits();
    
    return attacks;
}
