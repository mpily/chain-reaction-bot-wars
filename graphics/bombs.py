from graphics import *

class Bomb():
    margin_top       = 20
    margin_left      = 20
    cell_width       = 50
    cell_length      = 50
    radius           = 8
    colors_used      = 0
    colors           = ['red','orange','yellow','green','blue','violet','pink','cyan']
    owners_to_colors = {}
    def __init__(self,row,col,position,owner,margin_top = 20, margin_left = 20, cell_width = 50, cell_length = 50):
        self.row_position  = row
        self.col_position  = col
        self.cell_position = position
        self.owner         = owner
        self.setPosition()
        self.circle = Circle(Point(self.x_coord,self.y_coord),self.radius)
        if self.owner in Bomb.owners_to_colors:
            print(self.owner, "Is in the keys",Bomb.owners_to_colors[self.owner])
            self.circle.setFill(Bomb.owners_to_colors[self.owner])
        else:
            self.circle.setFill(Bomb.colors[Bomb.colors_used])
            Bomb.owners_to_colors[self.owner] = Bomb.colors[Bomb.colors_used]
            Bomb.colors_used += 1
    
    def setPosition(self):
        self.x_coord  = self.margin_left + self.cell_width * self.col_position + self.radius * 2 * self.cell_position + 8
        self.y_coord  = self.margin_top + self.cell_length * self.row_position + self.radius * 2 * self.cell_position + 8
        
    def draw(self,win):
        self.circle.draw(win)
     
    def undraw(self):
        self.circle.undraw()
