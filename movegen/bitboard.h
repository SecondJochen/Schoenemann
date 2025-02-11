#pragma once

#include <iostream>
#include <cstdint>
#include <sstream>
#include <bitset>
class Bitboard
{
public:
    Bitboard() : bits(0) {}
    Bitboard(std::uint64_t newBits) : bits(newBits) {}
    // This all is based on the concept that 1ULL is equal to
    // 0000000000000000000000000000000000000000000000000000000000000001
    // And we always shift this last set by an index we get

    // Clears a bit at a specific index
    // This is done by shifting the bit to the left with the index and then inverting the bit
    constexpr void clear(std::uint8_t index)
    {
        bits &= ~(1ULL << index);
    }

    // Clear the whole bitboard
    constexpr void clear()
    {
        bits = 0;
    }

    // Checks if a bit at a specific index is set to one
    constexpr bool check(std::uint8_t index)
    {
        return bits & (1ULL << index);
    }

    // Sets a bit at a specific index
    // This is done by shifting the bit to the left by the index
    constexpr void set(std::uint8_t index)
    {
        bits |= (1ULL << index);
    }

    // Returns the bits of the bitboard
    constexpr std::uint64_t getBits()
    {
        return bits;
    }

    // Returns a bitboard where only the square with the index is set
    // But this bit must also have been set beforehand
    Bitboard getFromSquare(std::uint8_t index)
    {
        // We take our whole bits and apply a mask that consists of one 1ULL that gets shifted by the index
        return Bitboard(bits & (1ULL << index));
    }

    // Converts the bitboard to a string
    std::string str() const noexcept
    {
        std::string bitset = std::bitset<64>(bits).to_string();

        std::stringstream stream;
        int counter = 0;
        for (int i = 0; i < 64; i++)
        {
            stream << bitset.substr(i, 1) << " ";
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

    constexpr Bitboard& operator|=(const Bitboard& bitboard) noexcept
    {
        bits |= bitboard.bits;
        return *this;
    }

    constexpr Bitboard& operator&=(const Bitboard& bitboard) noexcept
    {
        bits &= bitboard.bits;
        return *this;
    }

    Bitboard operator&(const Bitboard& bitboard) const noexcept
    {
        return Bitboard(bits & bitboard.bits);
    }

private:
    std::uint64_t bits;
};