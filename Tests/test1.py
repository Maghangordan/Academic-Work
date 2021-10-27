from array import *

def algo(arr):
    for x in range(3):
        if(sum(arr[x])==3 or sum(arr[x])==6):
            print("Someone won horizontally!")
        myCol = [arr[0][x],arr[2][x],arr[2][x]]
        print(myCol)
        if(sum(myCol)==3 or sum(myCol)==6):
            print("Someone won vertically!")
    

def main():
    myarr = [[0,0,1],[0,0,2],[0,0,1]]
    algo(myarr)

main()
