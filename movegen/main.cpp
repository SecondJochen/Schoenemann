#include <iostream>

#include "bitboard.h"
#include "attacks.h"

int main() 
{
    Bitboard bb;
    
    bb.set(63);
    std::cout << generateKingAttacks(bb).str();

    return 0;
}