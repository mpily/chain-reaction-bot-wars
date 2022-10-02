#include<iostream>

#include "input.hpp"
using namespace std;
int main(){
    string source = "../table.txt";
    InputReader test_input(source);
    test_input.readTable();
    cout << test_input.table_length << " " << test_input.table_width << "\n";
    for(int i = 0; i < test_input.table_length; ++i){
        for(int j = 0; j < test_input.table_width; ++j){
            cout << test_input.table_rep[i][j].toString() << " ";
        }
        cout << "\n";
    }
    return 0;
}
