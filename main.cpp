#include<iostream>
#include"engine.hpp"
int main(){
    std :: cout << "Enter number of rows, columns and players" << std::endl;
    int row, col, players;
    std::cin >> row >> col >> players;
    Game new_game(row,col,players);
    while(new_game.playRound());
    std :: cout << "winner is : " << new_game.getWinner() << "\n";
    return 0;
}
