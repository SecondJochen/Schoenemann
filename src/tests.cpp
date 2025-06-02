#include "tests.h"
#include "see.h"

void testSEE(chess::Board &board) {
    std::cout << "Running SEE tests..." << std::endl;

    std::ifstream inputFile("SEE.txt");
    assert(inputFile.is_open());

    std::string line = "";
    while (std::getline(inputFile, line))
    {
        std::stringstream iss(line);
        const std::vector<std::string> tokens = splitString(line, '|');

        const std::string fen = tokens[0];
        const std::string uciMove = tokens[1];
        const int gain = stoi(tokens[2]);

        board.setFen(fen);
        const Move move = uci::uciToMove(board, uciMove);

        assert(see(board, move, gain - 1));
        assert(see(board, move, gain));
        assert(!see(board, move, gain + 1));
    }

    inputFile.close();
    std::cout << "SEE tests passed" << std::endl;
}