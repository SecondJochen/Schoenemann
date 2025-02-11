#pragma once

#include "bitboard.h"
#include "coordinates.h"

template<const std::int8_t dir>
constexpr Bitboard shift(Bitboard bitboard)
{
    if constexpr (dir == Direction::NORTH)
    {
        return bitboard.getBits() << 8;
    }

    if constexpr (dir == Direction::SOUTH)
    {
        return bitboard.getBits() >> 8;
    }

    if constexpr (dir == Direction::EAST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_H)) << 1;
    }

    if constexpr (dir == Direction::WEST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_A)) >> 1;
    }

    if constexpr (dir == Direction::NORTH_EAST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_H)) << 9;
    }

    if constexpr (dir == Direction::SOUTH_EAST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_H)) >> 7;
    }

    if constexpr (dir == Direction::NORTH_WEST)
    {
        return (bitboard.getBits() & File::toBitboard(File::FILE_A)) << 7;
    }

    if constexpr (dir == Direction::SOUTH_WEST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_A)) >> 9;
    }
}

Bitboard generateKingAttacks(Bitboard& bitboard);

// TODO probably make a look-up table for common Knight positions
Bitboard generateKnighAttacks(Bitboard& bitboard);

Bitboard generateRockAttacks(Bitboard& occupied, std::uint8_t square);