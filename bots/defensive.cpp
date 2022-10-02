#include<iostream>
#include<utility>

#include"defensive.hpp"

int main(){
    defensive::Defensive instance;
    auto[row,col] = instance.makeMove();
    std::cout << row << " " << col << "\n";
    return 0;
}
