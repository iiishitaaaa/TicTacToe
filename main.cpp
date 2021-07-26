#include <iostream>
#include <string>
#include <stdlib.h>
#include "TicTacToe.hpp"
using namespace std;

void display_matrix(TicTacToe &player1, TicTacToe &player2);
void refresh_matrix(TicTacToe &player, TicTacToe &otherPlayer, int xCor, int yCor);
bool isWinner(TicTacToe &player);
bool isDraw(TicTacToe &player);

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

bool isWinner(TicTacToe &player)
{
    if(player.get_winner()) {
        cout << player.get_name() << " has won!" << endl;
        return true;    
    } else {
        return false;
    }
}

bool isDraw(TicTacToe &player)
{
    bool noZero {true};
    for(auto row: player.get_matrix()) {
        for(auto element: row) {
            if(element == 0)
                noZero = false;
        }
    }
    if(noZero) 
        cout << "The match is draw." << endl;
    return noZero;
}

bool isgameLost(TicTacToe &other_player)
{
    if(other_player.game_lost()==0)
        return true;
    else 
        return false;
}

void refresh_matrix(TicTacToe &player, TicTacToe &otherPlayer, int xCor, int yCor) {
    if(otherPlayer.update_matrix(xCor, yCor, player.get_identifier())) {
        player.update_matrix(xCor, yCor, player.get_identifier());
    } else {
        cout << "Move is not possible" << endl;
        cout << "Enter x and y coordinate : ";
        cin >> xCor >> yCor;
        refresh_matrix(player, otherPlayer, xCor, yCor);
    }
}

void clear_game(TicTacToe &player, TicTacToe &otherPlayer) {
    player.clear_matrix();
    otherPlayer.clear_matrix();
}

int main() {
    int match_count = 3;
    TicTacToe player1 {"Player1", 2, 'X', 1};
    TicTacToe player2 {"Player2", 2, 'O', 2};
    int xCor {}, yCor{};
    display_matrix(player1, player2);
    do
    {
        cout << player1.get_name() << " (" << player1.get_symbol() << ")" << endl;
        cout << "Enter x and y coordinate : ";
        cin >> xCor >> yCor;
        refresh_matrix(player1, player2, xCor, yCor);
        system("CLS");
        display_matrix(player1, player2);
        if(isWinner(player1)) {
            match_count--;
            clear_game(player1, player2);
            if(isgameLost(player2))
                break;
            continue;
        }
        if(isDraw(player1)) {
            clear_game(player1, player2);
            continue;
        }

        cout << player2.get_name() << " (" << player2.get_symbol() << ")" << endl;
        cout << "Enter x and y coordinate : ";
        cin >> xCor >> yCor;
        refresh_matrix(player2, player1, xCor, yCor);
        system("CLS");
        display_matrix(player1, player2);
        if(isWinner(player2)) {
            match_count--;
            clear_game(player2, player1);
            if(isgameLost(player1))
                break;
            continue;
        }
        if(isDraw(player2)) {
            clear_game(player2, player1);
            continue;
        }
        cout << "This is round " << (4 - match_count)  << endl;
    } while (true);
    
    return 0;
}