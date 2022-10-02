#include<iostream>
#include<fstream>
#include<vector>
#include<utility>

#include"../table.hpp"
#include"../cell.hpp"

#ifndef INPUT_READER
#define INPUT_READER
struct InputReader{
    
    int table_length;
    int table_width;
    std::vector<std::vector<Cell>> table_rep;
    std::string file_path;
    InputReader(std::string file){
        file_path = file;
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
    
    void readTable(){
        std::ifstream file_handler;
        file_handler.open(file_path);
        
        if(!file_handler){
            std::cerr << "bot input couldn't open file\n";
            exit(1);
        }
        file_handler >> table_length >> table_width;
        
        for(int i = 0; i < table_length; ++i){
            std::vector<Cell>nxt_row;
            for(int j = 0; j < table_width; ++j){
                int occupancy;
                char owner;
                file_handler >> owner >> occupancy;
                Cell nxt_cell(i,j,getCellType(i,j));
                nxt_cell.owner     = owner;
                nxt_cell.occupancy = occupancy;
                nxt_row.push_back(nxt_cell);
            }
            table_rep.push_back(nxt_row);
        }
        
    }
    
    Table getAsTable(){
        Table table_version(table_rep);
        return table_version;
    }
};
#endif
