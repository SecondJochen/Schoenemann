#pragma once

#include "bitboard.h"

class Direction
{
public:
    constexpr static std::int8_t NORTH = 8;
    constexpr static std::int8_t EAST = 1;
    constexpr static std::int8_t SOUTH = -NORTH;
    constexpr static std::int8_t WEST = -EAST;

    constexpr static std::int8_t NORTH_EAST = NORTH + EAST;
    constexpr static std::int8_t SOUTH_EAST = SOUTH + EAST;
    constexpr static std::int8_t SOUTH_WEST = SOUTH + WEST;
    constexpr static std::int8_t NORTH_WEST = NORTH + WEST;
};

const Bitboard FILE_MASKS[8] = {
    0x0101010101010101ULL, 0x0202020202020202ULL, 0x0404040404040404ULL, 0x0808080808080808ULL,
    0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL,
};

class File
{
public:
    constexpr static std::uint8_t FILE_A = 0;
    constexpr static std::uint8_t FILE_B = 1;
    constexpr static std::uint8_t FILE_C = 2;
    constexpr static std::uint8_t FILE_D = 3;
    constexpr static std::uint8_t FILE_E = 4;
    constexpr static std::uint8_t FILE_F = 5;
    constexpr static std::uint8_t FILE_G = 6;
    constexpr static std::uint8_t FILE_H = 7;

    static Bitboard toBitboard(std::uint8_t file)
    {
        return FILE_MASKS[file];
    }
};

class Rank
{
public:
    constexpr static std::uint8_t RANK_A = 0;
    constexpr static std::uint8_t RANK_B = 1;
    constexpr static std::uint8_t RANK_C = 2;
    constexpr static std::uint8_t RANK_D = 3;
    constexpr static std::uint8_t RANK_E = 4;
    constexpr static std::uint8_t RANK_F = 5;
    constexpr static std::uint8_t RANK_G = 6;
    constexpr static std::uint8_t RANK_H = 7;
};