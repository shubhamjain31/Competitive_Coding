n,k=map(int,input().split())
a=list(map(int,input().split()))
mod=10**9+7
track=[[a[0],0]]#will help us track the path with lowest product
for i in range(1,n):
    if i-track[0][1]>k:#eliminates the path which have length >k
        del track[0]
    
    temp=track[0][0]*a[i]
    while True:
        if track[-1][0]<=temp:
            break
        del track[-1] #as a path with lower product then presnt is their in p
        
    track.append([temp,i])
    
print(track[-1][0]%mod)
    