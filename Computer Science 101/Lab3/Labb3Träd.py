import tkinter
from math import sin, cos, radians

#Kod skriven av Magnus Danielsson, Högskoleingenjör Datateknik grupp 3 i kursen Datavetenskapens grunder
#2019-09-11

# DrawWindow - a class for creating a window with a canvas
class DrawingWindow(tkinter.Frame):
    def __init__(self):
        tkinter.Frame.__init__(self,None)
        self.canvas = tkinter.Canvas(self,width=500,height=500,bg='white')
        self.canvas.pack(expand=1,anchor=tkinter.CENTER)
        self.pack()

def draw_spiral(x,y,angle,dangle,length,dlength,steps,canvas):
    # x,y - starting position of the current line segment
    # angle - angle of current line segment (0 is straight up)
    # dangle - change in angle for each recursion
    # length - length of current line segment
    # dlength -  value to divide length with each step
    # steps - number of recursion steps left
    # canvas - canvas window to draw on
    if steps == 0:
        # Bas case -stop here
        pass
    else:
        # Recursive case
        # Draw one line segment from (x,y) with the given angle and length
        # Calulate end points of this line
        x2 = x+sin(radians(angle))*length
        y2 = y-cos(radians(angle))*length
        # Draw the line on the canvas
        canvas.create_line(x,y,x2,y2)
        # Recursive call, with end points the drawn lines as new start points,
        # with an increase in the angle (turn clockwise)
        # and a smaller length, and with step counted down with 1
        draw_spiral(x2,y2,angle+dangle,dangle,length/dlength,dlength,steps-1,canvas)


def draw_tree(x,y,angle,dangle,length,dlength,steps,canvas):
    
    if steps == 0:
        # Bas case -stop here
        pass
    else:
        # Recursive case
        # Draw one line segment from (x,y) with the given angle and length
        # Calulate end points of this line
        x2 = x+sin(radians(angle))*length
        y2 = y-cos(radians(angle))*length
        # Draw the line on the canvas
        canvas.create_line(x,y,x2,y2)
        
        
        draw_tree(x2,y2,angle+dangle,dangle,length/dlength,dlength,steps-1,canvas)
        draw_tree(x2,y2,angle-dangle,-dangle,length/dlength,dlength,steps-1,canvas)

def draw_tree3(x,y,angle,dangle,length,dlength,steps,canvas):
    # x,y - starting position of the current line segment
    # angle - angle of current line segment (0 is straight up)
    # dangle - change in angle for each recursion
    # length - length of current line segment
    # dlength -  value to divide length with each step
    # steps - number of recursion steps left
    # canvas - canvas window to draw on
    if steps == 0:
        # Bas case -stop here
        pass
    else:
        # Recursive case
        # Draw one line segment from (x,y) with the given angle and length
        # Calulate end points of this line
        x2 = x+sin(radians(angle))*length
        y2 = y-cos(radians(angle))*length
        # Draw the line on the canvas
        canvas.create_line(x,y,x2,y2)
        
        # Recursive call, with end points the drawn lines as new start points,
        # with an increase in the angle (turn clockwise)
        # and a smaller length, and with step counted down with 1
        draw_tree3(x2,y2,angle+dangle,dangle,length/dlength,dlength,steps-1,canvas)
        draw_tree3(x2,y2,angle-dangle,dangle,length/dlength,dlength,steps-1,canvas)
        draw_tree3(x2,y2,angle,dangle,length/dlength,dlength,steps-1,canvas)
        


# Create window for drawing on
w = DrawingWindow()


# Draw the spiral, the two branched tree, and three branched tree
# on the canvas of that window
# Try to change the parameters and see what happens
draw_spiral(50,50,90,60,100,1.1,35,w.canvas)

draw_tree(350,490,0,30,90,1.7,5,w.canvas)

draw_tree3(100,490,0,30,90,1.7,5,w.canvas)



# Start the window, so it is displayed


w.mainloop()
                

