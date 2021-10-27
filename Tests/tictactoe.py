from array import *
# This code is written as a gravestone for my confidence after completely flunking my first technical interview
# It only checks diagonals from bottom left to top right, but it's certainly better than what I could come up with on the spot.
class Board:
    
    def __init__(self):
        self.board = []
    def define_board(self):
        for x in range(3):
            row = []
            for y in range(3):
                row.append('-')
            self.board.append(row)
    
    def print_board(self):
        for row in self.board:
            for item in row:
                print(item, end=" ")
            print()
    
    def set_mark_p1(self, row, col):
        if(0<= row <=2 and 0<= col <=2 and self.board[row][col]=='-'):
            self.board[row][col]="X"
            print()
        else:
            print("Invalid input")
            print("Player 1 (X):")
            row, col = self.get_input()
            self.set_mark_p1(row, col)
            
    def set_mark_p2(self, row, col):
        if(0<= row <=2 and 0<= col <=2 and self.board[row][col]=='-'):
            self.board[row][col]="O"
        else:
            print("Invalid input")
            print("Player 2 (O):")
            row, col = self.get_input()
            self.set_mark_p2(row, col)
    def check_if_p1_won(self):
        p1Won = None
        #row win
        for x in range(3): 
            p1Won = True
            for y in range(3):
                if self.board[x][y]!='X':
                    p1Won = False
                    break;
            if p1Won:
                self.winner="Player 1"
                return p1Won
        #col win
        for x in range(3):    
            p1Won = True
            for y in range(3):
                if self.board[y][x]!='X': 
                    p1Won = False
                    break;
            if p1Won:
                self.winner="Player 1"
                return p1Won
        #diagonal win
            p1Won = True
            for x in range(3):
                if self.board[x][x]!='X':
                    p1Won = False
                    break;
            if p1Won:
                return p1Won
            return False

            p1Won = True
            for x in range(3):
                if self.board[x][2-x]!='X':
                    p1Won = False
                    break;
            if p1Won:
                return p1Won
            return False
    def check_if_p2_won(self):
        p2Won = None
        #row win
        for x in range(3):
            p2Won = True
            for y in range(3):
                if self.board[x][y]!='O': 
                    p2Won = False
                    break;
            if p2Won:
                self.winner="Player 2"
                return p2Won
        #col win    
        for x in range(3):
            p2Won = True
            for y in range(3):
                if self.board[y][x]!='O': 
                    p2Won = False
                    break;
            if p2Won:
                self.winner="Player 2"
                return p2Won
        #diagonal win
            p2Won = True
            for x in range(3):
                if self.board[x][x]!='O':
                    p2Won = False
                    break;
            if p2Won:
                return p2Won
            return False

            p2Won = True
            for x in range(3):
                if self.board[x][2-x]!='O':
                    p2Won = False
                    break;
            if p2Won:
                return p2Won
            return False    
    def start(self):
        self.define_board()
        self.print_board()
        print()
    def get_input(self):
        row, col = list(
                map(int, input("Enter row and column numbers to fix spot: ").split()))
        return row, col
    def is_not_full(self):
        for row in self.board:
            for item in row:
                if item =='-':
                    return True
        return False
def main():
    game = Board()
    game.start()
    
    while(True):
        if(game.is_not_full()):
            print("Player 1 (X):")
            row, col = game.get_input()
            game.set_mark_p1(row, col)
            if(game.check_if_p1_won()):
                print("Player 1 won!")
                game.print_board()
                break;
            game.print_board()
        else:
            print("Game is full, please restart")
            break;
        if(game.is_not_full()):
            print("Player 2 (O):")
            row, col = game.get_input()
            game.set_mark_p2(row, col)
            if(game.check_if_p2_won()):
                print("Player 2 won!")
                game.print_board()
                break;
            game.print_board()
        else:
            print("Game is full, please restart")
            break;
main()
