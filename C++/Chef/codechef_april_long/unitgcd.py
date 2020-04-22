# import inbuilt standard input output  
from sys import stdin, stdout  
from bisect import bisect_left 
import heapq 
  
 
def main(): 
  
    # input via readline method 
    t=int(input())
    for _ in range(t):    
        # array input similar method 
        n=int(input())
        arr = [int(x) for x in stdin.readline().split()] 
        idx=[]
        for i in range(len(arr)):
            if arr[i]%2==0:
                idx.append(i)
        ans=0
        for i in range(len(idx)):
            if arr[idx[i]]%4==2:
                if len(idx)==1:
                    ans+= (idx[i]+1)*(n-idx[i])
                    continue
                if i==0:
                    ans+= (idx[i]+1)*(idx[i+1]-idx[i])
                    continue
                if i==len(idx)-1:
                    ans+=(idx[i]-idx[i-1])*(n-idx[i])
                    continue
                ans+=(idx[i]-idx[i-1])*(idx[i+1]-idx[i])
        n=n*(n+1)
        n/=2
        ans=n-ans
        print(str(ans))


            
            

    #initialize variable 
    
# call the main method 
if __name__ == "__main__": 
    main()     