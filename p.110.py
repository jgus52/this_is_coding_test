N=int(input())
x, y=1, 1
input_list=input().split()

char_list=['L', 'R', 'U', 'D']
move_x=[-1, 1, 0, 0]
move_y=[0,0,-1, 1]

for input in input_list:
  for i in range(len(char_list)):
    if input==char_list[i]:
      nx=x+move_x[i]
      ny=y+move_y[i]
    
  if nx<1 or nx>N or ny<1 or ny>N:
    continue
  
  x,y = nx, ny

print(y,x)