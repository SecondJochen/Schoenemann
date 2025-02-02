#pragma once

#include "bitboard.h"
#include "coordinates.h"

template <Direction::underlying dir>
constexpr Bitboard shift(Bitboard bitboard)
{
    if constexpr (dir == Direction::underlying::NORTH)
    {
        return bitboard.getBits() << 8;
    }

    if constexpr (dir == Direction::underlying::SOUTH)
    {
        return bitboard.getBits() >> 8;
    }

    if constexpr (dir == Direction::underlying::EAST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_H)) << 1;
    }

    if constexpr (dir == Direction::underlying::WEST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_A)) >> 1;
    }

    if constexpr (dir == Direction::underlying::NORTH_EAST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_H)) << 9;
    }

    if constexpr (dir == Direction::underlying::NORTH_WEST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_A)) << 7;
    }

    if constexpr (dir == Direction::underlying::SOUTH_EAST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_H)) >> 7;
    }

    if constexpr (dir == Direction::underlying::SOUTH_WEST)
    {
        return (bitboard.getBits() & ~File::toBitboard(File::FILE_A)) >> 9;
    }
}

// TODO probably make a look-up table for common kngiht positions
Bitboard generateKingAttacks(Bitboard &bitboard);