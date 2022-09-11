#include<iostream>
#include<utility>
#include<vector>
#include<random>
using namespace std;
int main(){
    srand(time(0));
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
    while(true){
        int x = rand() % rows;
        int y = rand() % columns;
        if(grid[x][y].first == '*' || grid[x][y].first == '#'){
            cout << x << " " << y << "\n";
            return 0;
        }
    }
    return 0;
}
