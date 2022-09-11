# chain-reaction-bot-wars
Bot for chain reaction game
Currently the engine seems to be working but has not been thoroughly tested.
You can run as a bot or as a human
For C++ programs, first compile the program to obtain the binary

example:
if the C++ bot has been written in bot.cpp you can compile with:
g++ -std=c++17 bot.cpp -O3 -o  bot
to obtain the executable bot
the command to run is then ./bot (For linux system)

when running the bot, it takes the state of the board as input through standard input streams (cin etc.)
the state of the board is defined as a pair of the bot owner defined by a char and number of bombs in that square.

The input is as follows, the first line contains 2 integers the number of rows, r, and the number of columns,c.

the next r rows contain c states each (pairs of player and number of bombs). If the player of a cell is a Latin alphabet character ('a' to 'z' or 'A' to 'Z') it represents that another player occupies that cell and thus you should not play there. If it is a '#' it means the  cell is free. If it is a '*' it means that you currently occupy that cell.

For example:

4 5

\* 1 B 1 # 0 # 0 # 0 

\# 0 # 0 # 0 # 0 # 0 

\# 0 # 0 # 0 B 1 # 0 

\# 0 # 0 # 0 # 0 # 0 


In the above case cell 0,0 has one of your players, cell 0 1 and 2,3 has an opponents bomb.
Your bot should output 2 space separated integers the row ,a, and column ,b, it wishes to play.
It should be such that  0 <= a < length and 0 <= b < width.

A simple bot can be seen in sampleBot.cpp. Its technique is to fill the first square it can fill prioritising one that it already has bombs present.
....

In order to visualize the graphics, you can use the make_logs.py file. To use it, after running the game to completion, a file, logfile.txt will be generated in the graphics folder. cd to that folder and run the make_logs file.in order to move to the next state, click on the right half of the screen. to move to the previous state, click on the left half.
