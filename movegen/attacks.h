#pragma once

#include "bitboard.h"

class Direction
{
private:
    // underlying is choosen as the class name to avoid name collisions
    enum class underlying : std::int8_t
    {
        NORTH = 8,
        EAST = 1,
        SOUTH = -NORTH,
        WEST = -EAST,

        NORTH_EAST = NORTH + EAST,
        SOUTH_EAST = SOUTH + EAST,
        SOUTH_WEST = SOUTH + WEST,
        NORTH_WEST = NORTH + WEST
    };

    constexpr Direction(underlying newDirection) : direction(newDirection) {}

    underlying direction;

    template <Direction::underlying dir>
    friend constexpr Bitboard shift(Bitboard sq);

public:
    constexpr operator underlying() { return direction; }
    static constexpr Direction NORTH() { return underlying::NORTH; }
    static constexpr Direction SOUTH() { return underlying::SOUTH; }
    static constexpr Direction EAST() { return underlying::EAST; }
    static constexpr Direction WEST() { return underlying::WEST; }

    static constexpr Direction NORTH_EAST() { return underlying::NORTH_EAST; }
    static constexpr Direction NORTH_WEST() { return underlying::NORTH_WEST; }
    static constexpr Direction SOUTH_EAST() { return underlying::SOUTH_EAST; }
    static constexpr Direction SOUTH_WEST() { return underlying::SOUTH_WEST; }
};

template <Direction::underlying dir>
constexpr Bitboard shift(Bitboard bitboard)
{

    if constexpr (dir == Direction::underlying::NORTH)
    {
        return bitboard.getBits() << 8;
    }

    if constexpr (dir == Direction::underlying::SOUTH)
    {
        return bitboard >> 8;
    }
}

// TODO probably make a look-up table for common kngiht positions
Bitboard generateKingAttacks(Bitboard &bitboard);