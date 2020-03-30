# import inbuilt standard input output  
from sys import stdin, stdout  
from bisect import bisect_left 
import heapq 
  
# suppose a function called main() and 
# all the operations are performed 
def BinarySearch(a, x): 
	i = bisect_left(a, x) 
	if i: 
		return (i) 
	else: 
		return -1
  
def main(): 
  
    # input via readline method 
    t=int(input())
    faltu = stdin.readline() 
    for _ in range(t):    
        # array input similar method 
        n,m,a,b = [int(x) for x in stdin.readline().split()] 
        arr = [int(x) for x in stdin.readline().split()] 
        
        if _!=t-1:
            faltu = stdin.readline() 
        arr.sort()
        # if m==0:
        #     stdout.write(str(b-a))
        # else:
        d = b-a
        li = [a] 
        diff=0
        for i in range(1,m+1):
            temp = bisect_left(arr, (int)(d*i/(m+1))) -1
            print(d*i/(m+1))
            print("temp is ",temp," and ",arr[temp])
            # print(temp)
            heapq.heappush(li,arr[temp])
            print(diff)
            print(abs(li[i]-li[i-1]))
            print()
            diff = max(diff,abs(li[i]-li[i-1]))
            del arr[temp]
        diff=max(diff,abs(b-li[m]))
        print(str(diff))


            
            

    #initialize variable 
    
# call the main method 
if __name__ == "__main__": 
    main()     