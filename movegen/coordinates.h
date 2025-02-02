#include <iostream>
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
    friend constexpr Bitboard shift(Bitboard bitboard);

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

class File {
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
        return 0x0101010101010101 << file;
    }
};

class Rank {
private:
    enum class underlying : std::uint8_t
    {
        RANK_1 = 0,
        RANK_2 = 1,
        RANK_3 = 2,
        RANK_4 = 3,
        RANK_5 = 4,
        RANK_6 = 5,
        RANK_7 = 6,
        RANK_8 = 7
    };

    underlying ranks;
};
