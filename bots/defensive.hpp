#include<cstdlib>
#include<random>
#include<set>
#include<tuple>
#include<utility>
#include<vector>

#include"input.hpp"

#ifndef DEFENSIVE
#define DEFENSIVE
namespace defensive
{

struct RankCells{
    std::set<std::tuple<double,int,int>>ranked_cells;
    Table state;
    double infinity;
    double epsilon;
    double bias_factor;
    RankCells(Table curr_state){
        state       = curr_state;
        infinity    = 1e10;
        epsilon     = 1e-4;
        bias_factor = 0.1; 
    }
    double singleCellCompute(int row,int col){
        /*
            TODO : try to use different weights for cells that are owned by who
        */
        double score = 0;
        if(state.grid[row][col].owner != '*' && 
           state.grid[row][col].owner != '#'){
            return infinity;
        }
        for(int i = 0; i < state.table_length; ++i){
            for(int j = 0; j < state.table_width; ++j){
                int manhattan_distance = abs(row - i) + abs(col - j);
                if(manhattan_distance == 0){
                    continue;
                }
                
                score += (1.f/manhattan_distance) * 
                (double)state.grid[i][j].occupancy /
                state.grid[i][j].numNeighbours();
            }
        }
        score += bias_factor * 
                 (state.grid[row][col].numNeighbours() - 
                  state.grid[row][col].occupancy);
        return score;
    }

    void computeTable(){
        /*
            TODO: you can speed this up with dynamic programming
        */
        for(int i = 0; i < state.table_length; ++i){
            for(int j = 0;j < state.table_width; ++j){
                double cell_value = singleCellCompute(i,j);
                ranked_cells.insert(std::make_tuple(cell_value,i,j));
            }
        }
    }
};

struct Defensive{
    Table state;
    std::set<std::tuple<double,int,int>>ranked_cells;
    const std::string file_path = "table.txt";
    Defensive(){
        InputReader input_handler(file_path);
        input_handler.readTable();
        state = input_handler.getAsTable();
    }
    
    std::pair<int,int> makeMove(){
        RankCells rank_handler(state);
        rank_handler.computeTable();
        std::vector<std::pair<int,int>> candidate_moves;
        double best_value = rank_handler.infinity;
        for(auto [score,row,col] : rank_handler.ranked_cells){
            std::cerr << row << " , " << col << " has a score of : " << score << "\n";
            if(score < best_value){
                best_value = score;
            }
            if(score - rank_handler.epsilon > best_value){
                break;
            }
            else{
                candidate_moves.push_back(std::make_pair(row,col));
            }
        }
        if(candidate_moves.size() == 0){
            std::cerr << "defensive player could not generate any moves\n";
            exit(0);
        }
        srand(time(0));
        return candidate_moves[rand() % candidate_moves.size()];
    }
};

}
#endif
