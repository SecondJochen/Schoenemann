#include <iostream>

#include "bitboard.h"
#include "attacks.h"

int main() 
{
    Bitboard bb;
    
    bb.set(20);
    std::cout << bb.str() << std::endl << std::endl;
    std::cout << generateKnighAttacks(bb).str();

    return 0;
}