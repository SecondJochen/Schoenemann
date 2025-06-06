#include "tests.h"
#include "see_o.h"


void testSEE(Board &board) {
    std::cout << "Running SEE tests..." << std::endl;

    std::ifstream inputFile("see.txt");
    assert(inputFile.is_open());

    std::string line = "";
    while (std::getline(inputFile, line))
    {
        std::stringstream iss(line);
        const std::vector<std::string> tokens = splitString(line, '|');

        const std::string fen = tokens[0];
        const std::string uciMove = tokens[1];
        const int gain = std::stoi(tokens[2]);

        board.setFen(fen);
        const Move move = uci::uciToMove(board, uciMove);
        std::cout << "Position: " << fen << std::endl;
        assert(SEE::see(board, move, gain - 1));
        assert(SEE::see(board, move, gain));
        assert(!SEE::see(board, move, gain + 1));
    }

    inputFile.close();
    std::cout << "SEE tests passed" << std::endl;
}