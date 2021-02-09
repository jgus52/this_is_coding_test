n=int(input())

array=[]
for i in range(n):
  input_data=input().split()
  array.append((input_data[0], int(input_data[1])))

array.sort(key=lambda data: data[1])

for data in array:
  print(data[0], end=' ')