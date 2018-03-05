// ttt-not-terrorist-town.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

void main()
{
	// Initialize main game variables
	char squareNum[] = { 'x', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char originalNum[] = { 'x', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int playerTurn = 1;
	bool gameOver = true;
	// Main game loop
	do {
		// Print game board
		int loopCount = 1;
		cout << endl;
		for (int x = 1; x < 4; x++) {
			for (int y = 1; y < 4; y++)
			{
				cout << " " << squareNum[loopCount]; if (y < 3) { cout << " |"; } loopCount++;
			}
			if (x < 3)
			{
				cout << endl << "---+---+---";
			}
			cout << endl;
		}
		cout << endl;
		// Set player mark
		char playerMark = playerTurn == 1 ? 'X' : 'O';
		// Prompt player action
		cout << "Player " << playerTurn << "'s turn:";
		bool validAction;
		// Valid action loop
		do {
			int currAction;
			cin >> currAction;
			validAction = true;
			if (currAction < 10 && squareNum[currAction] == originalNum[currAction])
			{
				squareNum[currAction] = playerMark;
			}
			else { cout << "Invalid action, try again." << endl; }
		} while (!validAction);
		gameOver = false;
		bool winGame = true;
		// Check for end conditions
		if (squareNum[1] != '1') {
			if (squareNum[2] == squareNum[1] && squareNum[3] == squareNum[1]) { gameOver = true; }
			if (squareNum[4] == squareNum[1] && squareNum[7] == squareNum[1]) { gameOver = true; }
		}
		if (squareNum[5] != '5') {
			if (squareNum[2] == squareNum[5] && squareNum[8] == squareNum[5]) { gameOver = true; }
			if (squareNum[4] == squareNum[5] && squareNum[6] == squareNum[5]) { gameOver = true; }
			if (squareNum[3] == squareNum[5] && squareNum[7] == squareNum[5]) { gameOver = true; }
			if (squareNum[9] == squareNum[5] && squareNum[1] == squareNum[5]) { gameOver = true; }
		}
		if (squareNum[9] != '9') {
			if (squareNum[6] == squareNum[9] && squareNum[3] == squareNum[9]) { gameOver = true; }
			if (squareNum[8] == squareNum[9] && squareNum[7] == squareNum[9]) { gameOver = true; }
		}
		winGame = false;
		for (int z = 1; z < 11; z++) { if (z > 9) { gameOver = true; break; } if (squareNum[z] != originalNum[z]) { continue; } else { winGame = true; break; } }
		if (gameOver) {
			if (winGame) { cout << "Player " << playerTurn << " has won." << endl; }
			loopCount = 1;
			cout << endl;
			for (int x = 1; x < 4; x++) {
				for (int y = 1; y < 4; y++)
				{
					cout << " " << squareNum[loopCount]; if (y < 3) { cout << " |"; } loopCount++;
				}
				if (x < 3)
				{
					cout << endl << "---+---+---";
				}
				cout << endl;
			}
			cout << endl;
			cout << "Game over!" << endl << "Play again? y/n" << endl;
			char play2;
			cin >> play2;
			if (play2 == 'y') {
				gameOver = false;
				for (int z = 1; z < 10; z++) { squareNum[z] = originalNum[z]; }
			}
			playerTurn = 1;
			
		} else {
			playerTurn = playerTurn == 1 ? 2 : 1;
		}
	} while (!gameOver);
}