from graphics import *
def main():
    win = GraphWin("Test_grid", 1000, 1000)
    c = Circle(Point(50,50), 10)
    c.draw(win)
    win.getMouse() # Pause to view result
    win.close()    # Close window when done

main()
