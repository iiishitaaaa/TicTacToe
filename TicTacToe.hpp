#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_
#include <string>
#include <vector>

class TicTacToe
{
    private:
        std::string name{"Player"};
        int health{2};
        char symbol;
        int identifier;
        std::vector <std::vector<int>> matrix { 
            {0,0,0},
            {0,0,0},
            {0,0,0}
        }; 
    public:
        std::string get_name();
        int game_lost();
        int get_identifier();
        bool update_matrix(int xCor, int yCor, int place_val);
        bool get_winner();
        std::vector <std::vector<int>> get_matrix();
        void clear_matrix();
        char get_symbol();
        TicTacToe(std::string name_val, int health_val, char symbol_val, int identifier_val);
};
 
#endif