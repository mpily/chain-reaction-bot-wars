#include<iostream>
#include"engine.hpp"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<Cell>>grid;
    Table fun_table(n,m);
    for(int i = 0; i < n; ++i){
        vector<Cell>next_row;
        for(int j = 0; j < m; ++j){
            int num;char who;
            cin >> num >> who;
            if(num == 0){
                Cell next_cell(i,j,fun_table.grid[i][j].cell_type);
                next_row.push_back(next_cell);
            }
            else{
                Cell next_cell(i,j,fun_table.grid[i][j].cell_type);
                next_cell.occupied = true;
                next_cell.owner = who;
                next_cell.occupancy = num;
                next_row.push_back(next_cell);
            }
        }
        grid.push_back(next_row);
    }
    Table test(grid);
    test.playMove(0,0,'B');
    return 0;
}
