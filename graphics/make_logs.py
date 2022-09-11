from graphics import *
from grid import Grid
from bombs import Bomb

log_file = 'logfile.txt'

def readFile():
    content      = open(log_file,'r')
    parameters   = content.readline()
    parameters   = parameters.split()
    num_of_rows  = int(parameters[0])
    num_of_cols  = int(parameters[1])
    num_of_table = int(parameters[2])
    bombs        = []
    grid_table        = Grid(num_of_rows,num_of_cols)
    
    for table in range(num_of_table):
        my_bombs = []
        for row in range(num_of_rows):
        
            next_row = content.readline()
            next_row = next_row.split()
            who      = '#'
            how_many = 0
            know_who = False
            col_pos  = 0
            for token in  next_row:
                if know_who:
                    for i in range(int(token)):
                        my_bombs.append(Bomb(row,col_pos,i,who))
                    col_pos += 1
                    know_who = False
                else:
                    know_who = True
                    who      = token
        bombs.append(my_bombs)
        space = content.readline()
        
    details = {'grid' : grid_table,
    'bombs': bombs}
    return details
                        
                        
def displayState(bombs,win):
    
    for bomb in bombs:
        bomb.draw(win)

def removeState(bombs):
    for bomb in bombs:
        bomb.undraw()

def main():
    details  = readFile()
    win      = GraphWin("game_1", 1000, 1000)
    print(details['grid'])
    details['grid'].draw(win)
    curr_pos = 0
    displayState(details['bombs'][curr_pos],win)
    while True:
        click_point = win.getMouse() 
        if click_point.x > 500 and curr_pos < len(details['bombs']) - 1:
            removeState(details['bombs'][curr_pos])
            curr_pos += 1
            displayState(details['bombs'][curr_pos],win)
            
        elif click_point.x < 500 and curr_pos > 0 :
            removeState(details['bombs'][curr_pos])
            curr_pos -= 1
            displayState(details['bombs'][curr_pos],win)

if __name__ == '__main__':
    main()
