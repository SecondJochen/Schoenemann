/*
  This file is part of the Schoenemann chess engine written by Jochengehtab

  Copyright (C) 2024-2025 Jochengehtab

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef CONSTS_H
#define CONSTS_H

#include <iostream>

const std::string STARTPOS = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

// Bench depth
constexpr int benchDepth = 5;

constexpr int hashMoveScore = 500000;
constexpr int killerScore = 300000;
constexpr int promotion = 200000;
constexpr int goodCapture = 400000;
constexpr int badCapture = -500000;

constexpr int CORRHIST_LIMIT = 1024;
constexpr int MAX_PLY = 246;
constexpr int MAX_MOVES = 218;

constexpr int EVAL_MATE = 30000;
constexpr int EVAL_INFINITE = 31000;
constexpr int EVAL_NONE = 31100;
constexpr int EVAL_MATE_IN_MAX_PLY = EVAL_MATE - MAX_PLY;

constexpr int mateIn(const int ply) {
    return EVAL_MATE - ply;
}

constexpr int matedIn(const int ply) {
    return -EVAL_MATE + ply;
}


const std::string testStrings[] = {
    STARTPOS,
    "r2q4/pp1k1pp1/2p1r1np/5p2/2N5/1P5Q/5PPP/3RR1K1 b - -",
    "5k2/1qr2pp1/2Np1n1r/QB2p3/2R4p/3PPRPb/PP2P2P/6K1 w - -",
    "r2r2k1/2p2pp1/p1n4p/1qbnp3/2Q5/1PPP1RPP/3NN2K/R1B5 b - -",
    "8/3k4/p6Q/pq6/3p4/1P6/P3p1P1/6K1 w - -",
    "8/8/k7/2B5/P1K5/8/8/1r6 w - -",
    "8/8/8/p1k4p/P2R3P/2P5/1K6/5q2 w - -",
    "rnbq1k1r/ppp1ppb1/5np1/1B1pN2p/P2P1P2/2N1P3/1PP3PP/R1BQK2R w KQ -",
    "4r3/6pp/2p1p1k1/4Q2n/1r2Pp2/8/6PP/2R3K1 w - -",
    "8/3k2p1/p2P4/P5p1/8/1P1R1P2/5r2/3K4 w - -",
    "r5k1/1bqnbp1p/r3p1p1/pp1pP3/2pP1P2/P1P2N1P/1P2NBP1/R2Q1RK1 b - -",
    "r1bqk2r/1ppnbppp/p1np4/4p1P1/4PP2/3P1N1P/PPP5/RNBQKBR1 b Qkq -",
    "5nk1/6pp/8/pNpp4/P7/1P1Pp3/6PP/6K1 w - -",
    "2r2rk1/1p2npp1/1q1b1nbp/p2p4/P2N3P/BPN1P3/4BPP1/2RQ1RK1 w - -",
    "8/2b3p1/4knNp/2p4P/1pPp1P2/1P1P1BPK/8/8 w - -"
};

#endif
