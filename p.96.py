N,M=map(int, input().split())

result=-1

for i in range(N):
  data_list=list(map(int, input().split()))
  min_val=min(data_list)
  result=max(result, min_val)

print(result)
