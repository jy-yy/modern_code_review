#include <iostream>
#include <stdio.h>
#include <string>


bool isWin(char game[3][3]) {
	bool win = false;
	//raw
	if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
	if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
	// column
	if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
	if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
	// diagonal
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
	return win;
}

int  main() {
	int i, j;
	char game[3][3] = { ' ' }; // Tic-tac-toe
	char player1 = 'X';
	char player2 = 'O';
	bool turn = false; // false for player 1's turn, true for player 2's turn. Player 1 first.
	std::cout << "X = Player 1" << std::endl << "O = Player 2" << std::endl;
	int n = 0;
	for (n = 0; n < 9; n++) {
		if (turn == false)
			std::cout << "Player 1: ";
		else
			std::cout << "Player 2: ";
		std::cout << "Which cell to mark? i:[1..3], j:[1..3]: ";
		std::cin >> i >> j;
		if (i > 3 || i < 1 || j > 3 || i < 1 || game[i-1][j-1] == 'X' || game[i-1][j-1] == 'O') {
			std::cout << "wrong cell! Please mark again!\n";
			n--;
			continue;
		}
		if (turn == false) {
			game[i-1][j-1] = 'X'; //player1
		}
		else {
			game[i-1][j-1] = 'O'; //player2
		}
		if (isWin(game)) {
			std::cout << "Win!" << std::endl;
			break; // need to terminate the problem
		}
		// show current consolee
		std::cout << game[0][0] << "\t" << game[0][1] << "\t" << game[0][2] << std::endl;
		std::cout << game[1][0] << "\t" << game[1][1] << "\t" << game[1][2] << std::endl;
		std::cout << game[2][0] << "\t" << game[2][1] << "\t" << game[2][2] << std::endl;
		turn = !turn; // use the not-operator to change true to false or false to true.
	}
	if (n == 9) // all celles have been inputted above but no winner yet
		std::cout << "Tie!" << std::endl;

	// show the game to consolee
	std::cout << game[0][0] << "\t" << game[0][1] << "\t" << game[0][2] << std::endl;
	std::cout << game[1][0] << "\t" << game[1][1] << "\t" << game[1][2] << std::endl;
	std::cout << game[2][0] << "\t" << game[2][1] << "\t" << game[2][2] << std::endl;
	return 1;
}
 # new version
1.修改了输入无限制的问题
2.修改了重复写入的问题
3.修改了平局判定条件不清晰的问题
4.更新注释
