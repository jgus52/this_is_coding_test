n,m=map(int, input().split())
x,y,d=map(int, input().split())

move_x=[1,0,-1,0]
move_y=[0,1,0,-1]

array=[]
for i in range(n):
  array.append(list(map(int, input().split())))

array[x][y]=2
ret=1

def change_direction(d):
  d-=1
  if d<0:
    d=3
  
  return d


while True:
  check=True
  for i in range(4):
    d=change_direction(d)
    nx=x+move_x[d]
    ny=y+move_y[d]
    if array[nx][ny]==0 :
      array[nx][ny]=2;
      x=nx
      y=ny
      ret+=1
      check=False
      break

  if check:
    x=x-move_x[d]
    y=y-move_y[d]
    if array[x][y]==1:
      break
  
print(ret)

#c++로 만들고 해서 그런가 더 깔끔한 느낌이네