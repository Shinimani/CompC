t=input()
t=int(t)
while t>0:
    t-=1
    s=input()
    n=(int)(len(s))
    ans=0
    for i in range(1,(int)(n/2)):
        a = s[:i]
        i*=2
        m=(int)(n-i)
        m=(int)(m/2)
        b=s[i:i+m]
        ss = a+a+b+b
        if s==ss:
            ans+=1

    print(ans)
