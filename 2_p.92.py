N,M,K=map(int, input().split())
data_list=list(map(int, input().split()))

data_list.sort()

a=data_list[N-1]
b=data_list[N-2]


result=0

while M-K-1>=0:
  result += a*K+b
  M= M-K-1

if M>0:
  result=result + a*M

print(result)
