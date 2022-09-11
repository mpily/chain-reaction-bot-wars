#include<fstream>
#include<iostream>
#include"engine.hpp"
int main(){
    std :: cout << "Enter number of rows, columns and players" << std::endl;
    int row, col, players;
    std::cin >> row >> col >> players;
    Game new_game(row,col,players);
    while(new_game.playRound());
    
    
    std::ofstream log_file;
    log_file.open("graphics/logfile.txt");
    if(!log_file){
        std :: cerr << "had trouble opening logfile.txt file\n";
        exit(1);
    }
    log_file << new_game.game_table.table_length << " "
    << new_game.game_table.table_width << " " 
    << new_game.game_logs.size() << "\n";
    for(auto grid : new_game.game_logs){
        for(auto row : grid)             {
            for(auto cell : row)           {
                log_file << cell.owner << " " << cell.occupancy << " ";
            }
            log_file << "\n";
        }
        log_file << "\n";
    }
    
    
    std :: cout << "winner is : " << new_game.game_table.getWinner() << "\n";
    return 0;
}
