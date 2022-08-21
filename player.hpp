#include<cstdlib>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<utility>


#include"table.hpp"

#ifndef PLAYER
#define PLAYER

enum type_of_player{
    BOT,
    HUMAN
};

struct Player{
    type_of_player my_type;
    char player_initial;
    bool still_in;
    std::string file_path;
    
    Player(char initial, bool is_bot,std::string path ){
        if(is_bot){
            my_type    = BOT;
            file_path  = path;
        }
        else{
            my_type    = HUMAN;
        }
        player_initial = initial;
        still_in       = true;
    }
    
    Player(char initial){
        my_type        = HUMAN;
        still_in       = true;
        player_initial = initial;
    }
    
    void presentState(Table curr_state){
        if(my_type == BOT){
            std::ofstream text_file;
            text_file.open("table.txt");
            
            if(!text_file){
                std :: cerr << "had trouble opening table.txt file\n";
                exit(1);
            }
            
            text_file << curr_state.table_length << " " 
            << curr_state.table_width << "\n";
            
            for(int i = 0; i < curr_state.table_length; ++i){
                for(int j = 0; j < curr_state.table_width; ++j){
                    if(curr_state.grid[i][j].owner == player_initial){
                        text_file << "* ";
                    }
                    else{
                        text_file << curr_state.grid[i][j].owner << " ";
                    }
                    text_file << curr_state.grid[i][j].occupancy << " ";
                }
                text_file << "\n";
            }
            text_file.close();
            
        }
        else{
            for(int i = 0; i < curr_state.table_length; ++i){
                for(int j = 0; j< curr_state.table_width; ++j){
                    std :: cout << curr_state.grid[i][j].toString() << " ";
                }
                std :: cout << std :: endl;
            }
            std :: cout << std :: endl;
        }    
    }
    
    std::pair<int,int> my_move(Table curr_state){
        presentState(curr_state);
        int row, col;
        if(my_type == HUMAN){
            std :: cin >> row >> col;
        }
        else{
            std::string command = file_path + "< table.txt > sol.txt";
            system(command.c_str());
            std :: ifstream text_file;
            text_file.open("sol.txt");
            if(!text_file){
                std::cerr << "sol.txt not opening\n";
                exit(1);
            }
            text_file >> row >> col;
            text_file.close();
        }
        return std::make_pair(row,col);
    }
};

#endif
