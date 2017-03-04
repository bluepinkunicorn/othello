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
     this.side = side; // keep track of which side we are this game
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/* Check possible moves around a given token of other player
 * 
 */
std::vector <Move *> findPossMoves(int x, int y)
{
	// get a vector of empty spots around token
	std::vector<tuple<int, int>> emptySpots;
	for (int l = -1; l <= 1; l++)
	{
		if ((y+l < 8) && (y+l >= 0) && (x+1 < 8) && !self.board.occupied(x+1, y+l))
		{
			emptySpots.push_back(std::make_tuple(y+l, x+1));
		}
		if ((y+l < 8) && (y+l >= 0) && (x-1 >= 0) && !self.board.occupied(x-1, y+l))
		{
			emptySpots.push_back(std::make_tuple(y+l, x-1));
		}
	}
	if ((y-1 >= 0) && !self.board.occupied(x, y-1))
	{
		emptySpots.push_back(std::make_tuple(y-1, x));
	}
	if ((y+1 < 8) && !self.board.occupied(x, y+1))
	{
		emptySpots.push_back(std::make_tuple(y+1, x));
	}
	
	// get a vector of possible moves
	std::vector<tuple<int, int>> possMoves;
	for (int l = -1; l <= 1; l++)
	{
		for (int k = -1; k <= 1; k++)
		{
			if ((x-l > 0) && (x-l < 8) &&
				(y-k > 0) && (y-k < 8) && self.board.get(self.side, x-l, y-k))
			{
				possMoves.push_back(std::make_tuple(x-l, y-k));
			}
		}
	}
	return possMoves;
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
     
     
     // compile list of spots with opposite player on it
	std::vector <tuple<int, int>> possSpots;
	if side == BLACK;
	Side oppSide = white; // is this how its done?
	else {oppSide = black;}
	for (int i = 0; i < 9; i++)
	{
		for(int j =0; j < 9; j++)
		{
			if(board.get(side, i, j))
			{possSpots.push_back(std::make_tuple(i, j);}
	   }
	}

	// call possMoves
	std::vector <tuple<int, int>> possMoves;
	std::vector <tuple<int, int>> possMovesSpecific;
	for(int i=0; i < possMoves.size(); i++){
		possMovesSpecific = findPossMoves();
		for(int j=0; j < possMoves.size(); i++){
			possMoves[i].push_back(possMovesSpecific[j]);
		}
	}
    return nullptr;
}
