#include<iostream>
#include<queue>
#include<utility>
#include<vector>

#include"cell.hpp"

using std::vector;
#ifndef TABLE
#define TABLE
struct Table{
    int table_length,table_width;
    vector<vector<Cell>>grid;
    
    Table(int length = 8, int width = 8){
        table_length = length;
        table_width  = width;
        for(int i = 0; i < table_length; ++i){
            vector<Cell>next_row;
            for(int j = 0; j < table_width; ++j){
                type_of_cell current_cell_type = getCellType(i,j);
                Cell current_cell(i,j,current_cell_type);
                next_row.push_back(current_cell);
            }
            grid.push_back(next_row);
        }
    }

    bool isBoundary(int dimension, bool row_or_col){
        if(dimension == 0){
            return true;
        }
        else if(row_or_col){
            if(dimension == table_length - 1){
                return true;
            }
            else{ 
                return false;
            }
        }
        else{
            if(dimension == table_width - 1){
                return true;
            }
            else{
                return false;
            }
        }
    }
    
    type_of_cell getCellType(int row, int col){
        if(isBoundary(row,true) && isBoundary(col,false)){
            return CORNER_CELL;
        }
        else if(isBoundary(row,true) || isBoundary(col,false)){
            return EDGE_CELL;
        }
        else{
            return CENTER_CELL;
        }
    }
    
    bool outOfGrid(int row, int col){
        if(row < 0 || col < 0){
            return true;
        }
        else if(row >= table_length || col >= table_width){
            return true;
        }
        return false;
    }
    
    void processReaction(int row, int col,char player){
        int drow[4] = {-1,1,0,0};
        int dcol[4] = {0,0,-1,1};
        std :: queue<std::pair<int,int>>full_cells;
        full_cells.emplace(row,col);
        while(full_cells.size()){
            auto[curr_row,curr_col] = full_cells.front();
            //std :: cerr << curr_row << " " << curr_col << "being processed\n";
            full_cells.pop();
            while(grid[curr_row][curr_col].isFull()){
                for(int i = 0; i < 4; ++i){
                    int nxt_row = curr_row + drow[i];
                    int nxt_col = curr_col + dcol[i];
                    if(outOfGrid(nxt_row,nxt_col)){
                        continue;
                    }
                    grid[curr_row][curr_col].reduce();
                    grid[nxt_row][nxt_col].update(player);
                }
            }
            for(int i = 0; i < 4; ++i){
                int nxt_row = curr_row + drow[i];
                int nxt_col = curr_col + dcol[i];
                if(outOfGrid(nxt_row,nxt_col)){
                    continue;
                }
                if(grid[nxt_row][nxt_col].isFull()){
                    full_cells.emplace(nxt_row,nxt_col);
                }
            }
        }
    }
    
    int playMove(int row, int col,char player){
        if(outOfGrid(row,col)){
            return 1;
        }
        if(grid[row][col].owner != player && grid[row][col].owner != '#'){
            return 2;
        }
        
        grid[row][col].update(player);
        
        if(grid[row][col].isFull()){
            processReaction(row,col,player);    
        }
        return 0;
    }
    
};
#endif
