#include <iostream>

#include "bitboard.h"
#include "attacks.h"

int main() 
{
    Bitboard bb;
    Bitboard occ;

    occ.set(39);
    
    bb.set(20);
    std::cout << bb.str() << std::endl << std::endl;
    std::cout << generateRockAttacks(occ, 20).str();

    return 0;
}