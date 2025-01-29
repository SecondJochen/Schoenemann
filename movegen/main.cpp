#include <iostream>
#include <bitset>

#include "bitboard.h"
#include "attacks.h"

int main() 
{
    Bitboard bb;
    
    bb.set(28);
    std::cout << bb.str() << std::endl;
    std::cout << generateKingAttacks(bb).str();

    return 0;
}