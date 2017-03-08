#include "player.hpp"
// I made a change
/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
     
     // make a board
    Board board = Board();
    char data[64];
    for(int i = 0; i < 64; i++)
    {
		 data[i] = 'l';
		 if(i == 27 || i == 36)
		 {
			 data[i] = 'w';
		 }
		 else if(i == 28 || i == 35)
		 {
			 data[i] = 'b';
		 }
	}
	board.setBoard(data);
    this->side = side; // keep track of which side we are this game
     
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/* Check possible moves around a given token of other player
 * 
 */
std::vector <tuple<int, int>> Player::findPossMoves(int x, int y)
{
	std::vector<tuple<int, int>> possMoves;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			Move m = Move(x+i, y+j);
			if (x+i >= 0 && x+i < 8 && y+j >= 0 && y+j < 8 && 
				this->board.checkMove(&m, this->side))
			{
				possMoves.push_back(std::make_tuple(x+i, y+j));
			}
		}
	}
	return possMoves;
}

/* Checks if the given x, y coordinates is a corner piece.
 *
 */
bool Player::isCornerPiece(int x, int y)
{
	return (x==0 && y==0) || (x==0 && y==7) || (x==7 && y==0) || (x==7 && y==7);
}

/* Checks if the given x, y coordinates is an edge piece.
 * 
 */
bool Player::isEdgePiece(int x, int y)
{
	return x == 0 || y == 0 || x == 7 || y == 7;
}

bool Player::is_oppiCorner(int x, int y)
{
        return (x == 1 && y == 1) || (x == 6 && y == 6) || (x == 1 && y == 6) || (x == 6 && y == 1);
}
 
/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
	
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
     // add oponents move to board (check if nullptr first, make a board)*
     // check if any valid moves (pass if not)*
     // check if game over*
     // std::vector <Move> possibleMoves;
     // fill vector
     // choose random entry or return nullptr*
     // update board*
     
	
	// get opposite player color
	Side oppSide;
	if (this->side == BLACK)
	{
		oppSide = WHITE;
	}
	else 
	{
		oppSide = BLACK;
	}
	

	// add opponent's move to board
	board.doMove(opponentsMove, oppSide);	
	// compile list of spots with opposite player on it
	std::vector <std::tuple<int, int>> possSpots;
	
	for (int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(board.get(oppSide, i, j))
			{
				std::tuple<int, int> ij = std::make_tuple(i, j);
				possSpots.push_back(ij);
			}
	   }
	}
	
	// call possMoves
	std::vector <tuple<int, int>> possMoves;
	for(unsigned int i = 0; i < possSpots.size(); i++)
	{
		int x = std::get<0>(possSpots[i]);
		int y = std::get<1>(possSpots[i]);
		std::vector <tuple<int, int>> possMovesSpecific = findPossMoves(x, y);
		for(unsigned int j = 0; j < possMovesSpecific.size(); j++)
		{
			possMoves.push_back(possMovesSpecific[j]);
		}
	}
	
	// check if possMoves empty
	if (possMoves.size() == 0)
	{
		return nullptr;		
	}
	else
	{
		int bestX, bestY;
		bool check = false;
		for (unsigned int i = 0; i < possMoves.size(); i++)
		{
			if (isEdgePiece(std::get<0>(possMoves[i]), std::get<1>(possMoves[i])))
			{
				bestX = std::get<0>(possMoves[i]);
				bestY = std::get<1>(possMoves[i]);
				check = true;
			}
			else if (isCornerPiece(std::get<0>(possMoves[i]), std::get<1>(possMoves[i])))
			{
				bestX = std::get<0>(possMoves[i]);
				bestY = std::get<1>(possMoves[i]);
				check = true;
			}
		}
		if (check)
		{
			Move * move = new Move(bestX, bestY);
			board.doMove(move, this->side);
			return move;
		}
		else
		{
			//choose random move
			int size = possMoves.size();
			int index = rand() % size;
			Move * move = new Move(std::get<0>(possMoves[index]), std::get<1>(possMoves[index]));
			board.doMove(move, this->side);
			return move;
		}
	}
}

/**
 * Check if WHITE can make a move given BLACK's most recent move.
 */
bool Player::whiteCanMove(Move *opponentsMove, Board *tempBoard) {

	// this side is white
	Side oppSide = BLACK;
	
	// add BLACK's move to board
	tempBoard->doMove(opponentsMove, oppSide);	
	// compile list of spots with opposite player on it
	std::vector <std::tuple<int, int>> possSpots;
	
	for (int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(tempBoard->get(oppSide, i, j))
			{
				std::tuple<int, int> ij = std::make_tuple(i, j);
				possSpots.push_back(ij);
			}
	   }
	}
	
	// call possMoves
	std::vector <tuple<int, int>> possMoves;
	for(unsigned int i = 0; i < possSpots.size(); i++)
	{
		int x = std::get<0>(possSpots[i]);
		int y = std::get<1>(possSpots[i]);
		std::vector <tuple<int, int>> possMovesSpecific = findPossMoves(x, y);
		for(unsigned int j = 0; j < possMovesSpecific.size(); j++)
		{
			possMoves.push_back(possMovesSpecific[j]);
		}
	}
	
	// check if possMoves empty
	if (possMoves.size() == 0)
	{
		return false;		
	}
	else
	{
		return true;
	}
}
