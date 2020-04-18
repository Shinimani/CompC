from sys import stdin, stdout  
  
# suppose a function called main() and 
# all the operations are performed 
def main(): 
  
    # input via readline method 
    t = int(stdin.readline())
    # n=0
    while t>0:
        t=t-1
        n=int(stdin.readline())
        ans=0
        arra = [int(x) for x in stdin.readline().split()] 
        arrb = [int(x) for x in stdin.readline().split()]  
        # sorted(arra)
        # sorted(arrb)
        arra.sort()
        arrb.sort()
        for i in range(0,n):
            # print(min(arra[i],arrb[i]))
            ans = ans + min(arra[i],arrb[i])
        stdout.write(str(ans)) 

    # # n = stdin.readline() 
  
    # # array input similar method 
    # arr = [int(x) for x in stdin.readline().split()] 
  
    # #initialize variable 
    # summation = 0
      
    # # calculate sum 
    # for x in arr: 
    #     summation += x 
  
    # # could use inbuilt summation = sum(arr) 
  
    # # print answer via write 
    # # write method writes only 
    # # string operations 
    # # so we need to convert any 
    # # data into string for input 
    # stdout.write(str(summation)) 
  
# call the main method 
if __name__ == "__main__": 
    main()     