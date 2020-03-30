t=int(input())
faltu=input()
for _ in range(t):    
    n,m,n1,n2 = [int(x) for x in input().split()]
    arr=[int(x) for x in input().split()]
    if _!=t-1:
        faltu1=input()
    arr.sort()
    if m==0:
        print(abs(n1-n2))
    else:
        temp=min(n1,n2)
        if temp!=n1:
            temp1=n1
            n1=n2
            n2=temp1
        finalarr=[]
        finalarr.append(n1)
        finalarr.append(n2)
        for i in range(1):
            temp=(n2-n1)/2
            arrtemp=[]
            for j in range(n):
                arrtemp.append(abs(arr[j]-temp))
            temp2=min(arrtemp)
            print(arrtemp)
            
            if (temp2+temp) in arr:
                x=temp2+temp
            else:
                x=temp-temp2
            finalarr.append(x)
            finalarr.sort()
        # for i in range(m-1):
        #     for 
        #     arrtemp=[]
        #     for j in range(n):
        #         arrtemp.append(abs(arr[j]-temp))
        #     temp2=min(arrtemp)
        #     print(arrtemp)
            
        #     if (temp2+temp) in arr:
        #         x=temp2+temp
        #     else:
        #         x=temp-temp2
        #     finalarr.append(x)
        #     finalarr.sort()
        ans=0
        for i in range(1,len(finalarr)):
            ans=max(ans,finalarr[i]-finalarr[i-1])
        print(int(ans))
            




