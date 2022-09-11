from graphics import *

class Grid():
    number_of_rows   = 0
    number_of_cols   = 0
    horizontal_lines = []
    vertical_lines   = []
    margin_top       = 20
    margin_left      = 20
    cell_width       = 50
    cell_length      = 50
    def __init__(self,rows,cols,margin_top = 20, margin_left = 20, cell_length = 10, cell_width = 10):
        self.number_of_rows = rows
        self.number_of_cols = cols
        self.makeVerticalLines()
        self.makeHorizontalLines()
        
    def makeVerticalLines(self):
        for line_position in range(self.number_of_cols + 1):
            x_coord        = line_position * self.cell_width + self.margin_left
            y_coord_top    = self.margin_top
            y_coord_bottom = self.margin_top + self.cell_length * self.number_of_rows
            self.vertical_lines.append(Line(Point(x_coord,y_coord_top),Point(x_coord,y_coord_bottom)))

    def makeHorizontalLines(self):
        for line_position in range(self.number_of_rows + 1):
            x_coord_left  = self.margin_left
            x_coord_right = self.margin_left + self.cell_width * self.number_of_cols
            y_coord       = line_position * self.cell_length + self.margin_top
            self.horizontal_lines.append(Line(Point(x_coord_left,y_coord), Point(x_coord_right,y_coord)))
            
    def draw(self,win):
    
        for line in self.horizontal_lines:
            line.draw(win)
                       
        for line in self.vertical_lines:
            line.draw(win)
