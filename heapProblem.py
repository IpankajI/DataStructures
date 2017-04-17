import heapq
class maxH:
    def __init__(self):
        self.l=[]
    def insert(self,v):
        heapq.heappush(self.l,-v)
    def pop(self):
        return -heapq.heappop(self.l)
    def emp(self):
        if(len(self.l)>0):
            return True
        else:
            return False
    def mxEl(self):
        return -self.l[0]
    def size(self):
        return len(self.l)
    def p(self):
        print(self.l)
class minH:
    def __init__(self):
        self.l=[]
    def insert(self,v):
        heapq.heappush(self.l,v)
    def pop(self):
        return heapq.heappop(self.l)
    def emp(self):
        if(len(self.l)>0):
            return True
        else:
            return False
    def mnEl(self):
        return self.l[0]
    def size(self):
        return len(self.l)
    def p(self):
        print(self.l)
mxH=maxH()
mnH=minH()
t=int(input())
a=0
b=0
a=int(input())
t-=1
print(a)
if(t>0):
    b=int(input())
    print((a+b)//2)
    t-=1
    if(a>b):
        mxH.insert(b)
        mnH.insert(a)
    else:
        mxH.insert(a)
        mnH.insert(b)
while(t>0):
    t-=1
    n=int(input())
    ans=0
    x=-1
    mnS=mnH.size()
    mxS=mxH.size()
    if(mnS>mxS):
        x=mnH.pop()
    elif(mnS< mxS):
        x=mxH.pop()
    if(x!=-1):
        if(n>x):
            mnH.insert(n)
            mxH.insert(x)
        else:
            mnH.insert(x)
            mxH.insert(n)
    else:
        if(n>=mnH.mnEl()):
            mnH.insert(n)
        else:
            mxH.insert(n)
    mnS=mnH.size()
    mxS=mxH.size()
    if(mxS>mnS):
        print(mxH.mxEl())
    elif(mxS<mnS):
        print(mnH.mnEl())
    else:
        print((mnH.mnEl()+mxH.mxEl())//2)


#http://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0