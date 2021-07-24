#include <iostream>
#include <string>
#include <stdlib.h>
#include "TicTacToe.hpp"
using namespace std;

void display_matrix(TicTacToe &player1, TicTacToe &player2);

void display_matrix(TicTacToe &player1, TicTacToe &player2) {
    vector <vector <int>> matrix = player1.get_matrix();
    for(auto n: matrix) {
        for(auto m: n) {
            cout << "|";
            if(m == 0) {
                cout << " ";
            } else if(m == 1) {
                cout << player1.get_symbol();
            } else {
                cout << player2.get_symbol();
            }
        }
        cout << "|" << endl;
    }
}


int main() {
    int match_count = 3;
    TicTacToe player1 {"Player1", 2, 'X', 1};
    TicTacToe player2 {"Player2", 2, 'O', 2};
    int xCor {}, yCor{};
    display_matrix(player1, player2);
}