#include<string>
#ifndef CELL
#define CELL
enum type_of_cell{
    CORNER_CELL,
    EDGE_CELL,
    CENTER_CELL
};

struct Cell{
    type_of_cell cell_type;
    bool occupied;
    char owner;
    int row, col, occupancy;
    
    Cell(int row_val, int col_val, type_of_cell type){
        row       = row_val;
        col       = col_val;
        occupied  = false;
        cell_type = type;
        owner     = '#';
        occupancy = 0;
    }
    
    Cell(){
        occupied  = false;
        cell_type = CORNER_CELL;
    }
    
    void update(char player){
        owner      = player;
        occupancy += 1;
    }
    
    void reduce(){
    	occupancy -= 1;
    	if(occupancy == 0){
    	    owner = '#';
    	}
    }
    
    bool isFull(){
        if(occupancy >= numNeighbours()){
            return true;
        }
        else{
            return false;
        }
    }
    
    int numNeighbours(){
        if(cell_type == CORNER_CELL){
            return 2;
        }
        else if(cell_type == EDGE_CELL){
            return 3;
        }
        else{
            return 4;
        }
    }
    
    std::string toString(){
        std :: string string_rep = "";
        if(occupancy == 1){
            string_rep  = "__";
            string_rep += owner;
            string_rep += "_"; 
        }
        else if(occupancy == 2){
            string_rep = "_";
            string_rep += owner;
            string_rep += owner;
            string_rep += "_";
        }
        else if(occupancy == 3){
            string_rep += "_";
            string_rep += owner;
            string_rep += owner;
            string_rep += owner;
        }
        else{
            for(int i = 0; i < 4; ++i)
                string_rep += owner;
        }
        return string_rep;
    }
};
#endif
