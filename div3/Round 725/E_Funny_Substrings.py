t=int(input())
for _ in range(t):
    n=int(input())
    haha={}
    st={}
    end={}
    for rr in range(n):
        s=input()
        z=1
        for i in s:
            if(i=='+'):
                z=2
                break
        s=s.split()
        if(z==1):
            cnt=0
            for i in range(len(s[2])):
                tmp=s[2][i:i+4]
                if(tmp=="haha"):
                    cnt+=1
            haha[s[0]]=cnt
            st[s[0]]=s[2][0:3]
            end[s[0]]=s[2][-3:-1]+s[2][-1]
            if(rr==n-1):
                print(cnt)
        else:
            c=s[0]
            a=s[2]
            b=s[4]

            cnt=haha[a]+haha[b]

            s1=end[a]+st[b]
            for i in range(len(s1)):
                tmp=""
                tmp+=s1[i:i+4]
                if(tmp=="haha"):
                    cnt+=1

            haha[s[0]]=cnt

            st1=st[a]+st[b]
            st[c]=st1[0:3]

            end1=end[a]+end[b]
            end[c]=end1[-3:-1]+end1[-1]

            if(rr==n-1):
                print(cnt)

