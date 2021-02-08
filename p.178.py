n=int(input())

data_list=[]
for i in range(n):
  data_list.append(int(input()))

data_list.sort(reverse=True)

for i in data_list:
  print(i,end=' ')

#입출력이 은근히 헷갈리네?