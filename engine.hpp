#include<iostream>
#include<set>
#include<stdlib.h>
#include<string>
#include<vector>
#include<utility>


#include "player.hpp"
#include "table.hpp"
#ifndef BOTWARSENGINE
#define BOTWARSENGINE

struct Move{
    int     row;
    int     col;
    char player;
};

struct Game{
    std::vector<Move> moves_played;
    std::vector<Player>players;
    int num_of_players;
    bool first_round;
    Table game_table;
    
    Game(int row, int col,int num_players){
        Table temp(row,col);
        game_table     = temp;
        std:: cerr << game_table.table_length << " " << game_table.table_width <<"\n";
        first_round    = true;
        num_of_players = num_players;
        capturePlayerDetails();
    }
    
    void capturePlayerDetails(){
        for(int i = 0; i < num_of_players; ++i){
            std :: cout << "Enter player initial" << std :: endl;
            char initial;
            std :: cin >> initial;
            
            std :: cout << "Is player a bot ? 1 for Yes 0 for No" << std :: endl;
            char is_bot;
            std :: cin >> is_bot;
            
            if(is_bot == '1'){
                std :: cout << "Enter command to run the bot" << std :: endl;
                std :: string command;
                std :: cin >> command;
                Player new_player(initial, true, command);
                players.push_back(new_player);
            }
            else{
                Player new_player(initial);
                players.push_back(new_player);
            }
        }
        std :: cout << "Let the game begin!!\n\n";
    }
    
    bool playerStillIn(Player & player){
    	if(first_round){
    	    return true;
    	}
        for(int i = 0; i < game_table.table_length; ++i){
            for(int j = 0; j < game_table.table_width; ++j){
                if(game_table.grid[i][j].owner == player.player_initial){
                    return true;
                }
            }
        }
        player.still_in = false;
        return false;
    }
    
    bool gameOver(){
        std :: set<char>present_players;
        
        for(int i = 0; i < game_table.table_length; ++i){
            for(int j = 0; j < game_table.table_width; ++j){
                if(game_table.grid[i][j].occupancy == 0){
                    continue;
                }
                else if(present_players.count(game_table.grid[i][j].owner)){
                    continue;
                }
                else{
                    present_players.insert(game_table.grid[i][j].owner);
                }
            }
        }
        
        if((int)present_players.size() == 1){
            return true;
        }
        else{
            return false;
        }
    }
    
    char getWinner(){
        for(int i = 0; i < game_table.table_length; ++i){
            for(int j = 0; j < game_table.table_width; ++j){
                if(game_table.grid[i][j].occupancy){
                    return game_table.grid[i][j].owner;
                }
            }
        }
        std :: cerr << "There is no winner :(\n";
        exit(2);  
    }
    
    int playRound(){
        if(gameOver()){
            std :: cout << "game is over !\n";
            return 0;
        }        
        for(int i = 0; i < num_of_players; ++i){
            if(players[i].still_in && playerStillIn(players[i])){
                
                auto [row,col]  = players[i].my_move(game_table);
                int play_result = game_table.playMove(row,col,players[i].player_initial);
                
                if(play_result){
                    std :: cerr << "wrong cell play again error code : " << play_result << "\n";
                    i--;
                }
                else{
                    continue;
                }
            }
            else{
                continue;
            }
        }
        first_round = false;
        return 1;
    }
    
    
};
#endif
