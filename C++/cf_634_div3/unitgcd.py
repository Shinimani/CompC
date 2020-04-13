# import inbuilt standard input output  
from sys import stdin, stdout  
from bisect import bisect_left 
import heapq 
  
 
def main(): 
  
    # input via readline method 
    t=int(input())
    # sud=[]
    for _ in range(t):    
        sud=[]
        for i in range(9):
            str=stdin.readline()
            sud.append(str)
        for i in range(9):
            for j in range(9):
                if sud[i][j]=='1':
                    sud[i][j]='2'
                    print(sud[i])
                    break
        
        # array input similar method 
        # n=int(input())
        # arr = [int(x) for x in stdin.readline()] 
        # print(str(ans))


            
            

    #initialize variable 
    
# call the main method 
if __name__ == "__main__": 
    main()     