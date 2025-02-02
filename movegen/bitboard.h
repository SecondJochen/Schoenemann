#pragma once

#include <iostream>

// Important for std::uint64_t
#include <cstdint>

// Important for std::stringstream
#include <sstream>

#include <bitset>
class Bitboard
{
public:
    Bitboard() : bits(0) {}
    Bitboard(std::uint64_t newBits) : bits(newBits) {}
    // This all is based on the concet that 1ULL is equal to
    // 0000000000000000000000000000000000000000000000000000000000000001
    // and we always shift this last set by an index

    constexpr void clear(std::uint8_t index)
    {
        bits &= ~(1ULL << index);
    }

    constexpr void clear()
    {
        bits = 0;
    }

    constexpr bool check(std::uint8_t index)
    {
        return bits & (1ULL << index);
    }

    constexpr void set(std::uint8_t index)
    {
        bits |= (1ULL << index);
    }

    constexpr std::uint64_t getBits()
    {
        return bits;
    }

    Bitboard getFromSquare(std::uint8_t index)
    {
        // We take our whole bits and apply a maske the consits of one 1ULL that gets shifted by the index
        return Bitboard(bits & (1ULL << index));
    }

    std::string str()
    {
        std::bitset<64> bitset(bits);
        std::string str_bitset = bitset.to_string();

        std::stringstream stream;
        int counter = 0;
        for (int i = 0; i < 64; i++)
        {
            stream << str_bitset.substr(i, 1) << " ";
            if ((i + 1) % 8 == 0)
            {
                counter++;
                stream << " " << counter << std::endl;
            }
        }

        stream << std::endl;

        for (std::uint8_t i = 97; i < 105; i++)
        {
            stream << static_cast<char>(i) << " ";
        }

        return stream.str();
    }

    inline operator int()
    {
        return bits;
    }

    constexpr Bitboard &operator|=(const Bitboard &bitboard) noexcept
    {
        bits |= bitboard.bits;
        return *this;
    }

    Bitboard operator&(const Bitboard &bitboard) const noexcept
    {
        return Bitboard(bits & bitboard.bits);
    }

private:
    std::uint64_t bits;
};