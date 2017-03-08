#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <tuple>
#include <vector>
#include "common.hpp"
#include "board.hpp"
// #include <stdio.h>
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    std::vector <tuple<int, int>>findPossMoves(int x, int y);
    bool isCornerPiece(int x, int y);
    bool isEdgePiece(int x, int y);
    bool whiteCanMove(Move *opponentsMove, Board *tempBoard);
    bool is_oppiCorner(int x, int y);
    

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
    Side side; // which side our player is for this game
    Board board;
};

#endif
