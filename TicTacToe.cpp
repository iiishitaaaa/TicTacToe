#include "TicTacToe.hpp"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe(std::string name_val, int health_val, char symbol_val, int identifier_val)
  : name{name_val}, health{health_val}, symbol{symbol_val}, identifier{identifier_val} {
}

std::string TicTacToe::get_name()
{
    return name;
}

char TicTacToe::get_symbol()
{
    return symbol;
}

std::vector <std::vector<int>> TicTacToe::get_matrix()
{
    return matrix;
}

bool TicTacToe::update_matrix(int xCor, int yCor, int place_val)
{
    if (matrix.at(xCor).at(yCor) == 0) 
    {
        matrix.at(xCor).at(yCor) = place_val;
        return true;
    }
    else 
    {
        std::cout << "Move is not possible" << std::endl;
        return false;
    }
}

int TicTacToe::get_identifier()
{
    return identifier;
}

bool TicTacToe::get_winner()
{
    bool isWinner {false};
    for (size_t i{0}; i<3; i++)
    {
        if(matrix.at(i).at(0) == identifier && matrix.at(i).at(1) == identifier && matrix.at(i).at(2) == identifier) {
            isWinner = true;
            break;
        }

        if(matrix.at(0).at(i) == identifier && matrix.at(1).at(i) == identifier && matrix.at(2).at(i) == identifier) {
            isWinner = true;
            break;
        }
    }

    if(matrix.at(0).at(0) == identifier && matrix.at(1).at(1) == identifier && matrix.at(2).at(2) == identifier) {
        isWinner = true;
    }

    if(matrix.at(0).at(2) == identifier && matrix.at(1).at(1) == identifier && matrix.at(2).at(0) == identifier) {
        isWinner = true;
    }
    return isWinner;
}

int TicTacToe::game_lost()
{
    health--;
    return health;
}

void TicTacToe::clear_matrix()
{
    matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
}