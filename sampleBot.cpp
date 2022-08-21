#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int main(){
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<pair<char,int>>>grid;
    grid.resize(rows);
    for(int i = 0; i < rows; ++i){
        grid[i].resize(columns);
    }
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            cin >> grid[i][j].first >> grid[i][j].second;
        }
    }
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            if(grid[i][j].first == '*'){
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            if(grid[i][j].first == '#'){
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
    return 0;
}
