n,m=map(int, input().split())
ret=0

arr=[]
for i in range(n):
    arr.append(list(map(int,input())))

def DFS(x, y):
    if x<0 or y<0 or x>=n or y>=m:
        return False
    if arr[x][y]==0:
        arr[x][y]=1
        DFS(x+1,y)
        DFS(x-1,y)
        DFS(x,y+1)
        DFS(x,y-1)
        return True
    return False

for i in range(n):
    for j in range(m):
        if DFS(i,j)==True:
            ret+=1

print(ret)
