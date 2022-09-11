from graphics import *
from grid import Grid
from bombs import Bomb

def main():
    win       = GraphWin("test_grid", 1000, 1000)
    test_grid = Grid(8,10)
    test_grid.draw(win)
    
    test_bombs = [Bomb(0,0,0,'B'), Bomb(1,5,0,'B'), Bomb(1,5,1,'B'),Bomb(1,5,2,'B'),Bomb(2,2,0,'C'), Bomb(6,6,0,'C'), Bomb(3,6,0,'D')]
    
    for bomb in test_bombs:
        bomb.draw(win)
        
    
    while True:
        win.getMouse() # Pause to view result
    #win.close()    # Close window when done
    
if __name__ == '__main__':
    main() 
