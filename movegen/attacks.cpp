#include "attacks.h"

Bitboard generateKingAttacks(Bitboard& bitboard)
{
    Bitboard attacks;
    // We loop over all squares and create a bitboard
    // From that square we create a bitboard but only if the square is set beforehand
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

Bitboard generateKnighAttacks(Bitboard& bitboard)
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

Bitboard generateRockAttacks(Bitboard& occupied, std::uint8_t square)
{
    Bitboard attacks;
    Bitboard squareBitboard;

    squareBitboard.clear();
    squareBitboard.set(square);


    // The bitboard gets shifted to the north until it is zero
    while (squareBitboard.getBits())
    {
        attacks |= squareBitboard;
        if (occupied & squareBitboard)
        {
            break;
        }
        squareBitboard = shift<Direction::NORTH>(squareBitboard);
    }

    squareBitboard.clear();
    squareBitboard.set(square);

    while (squareBitboard.getBits())
    {
        attacks |= squareBitboard;
        if (occupied & squareBitboard)
        {
            break;
        }
        squareBitboard = shift<Direction::SOUTH>(squareBitboard);
    }

    squareBitboard.clear();
    squareBitboard.set(square);

    while (squareBitboard.getBits())
    {
        attacks |= squareBitboard;
        if (occupied & squareBitboard)
        {
            break;
        }
        squareBitboard = shift<Direction::EAST>(squareBitboard);
    }

    squareBitboard.clear();
    squareBitboard.set(square);

    while (squareBitboard.getBits())
    {
        attacks |= squareBitboard;
        if (occupied & squareBitboard)
        {
            break;
        }
        squareBitboard = shift<Direction::WEST>(squareBitboard);
    }

    attacks.clear(square);

    return attacks;
}