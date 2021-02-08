n,k=map(int, input().split())

A=list(map(int, input().split()))
B=list(map(int, input().split()))

A.sort()
B.sort(reverse=True)

for i in range(k):
  if A[i]<B[i]:
    A[i],B[i]=B[i],A[i]
  else:
    break

print(sum(A))

#라이브러리가 깡패긴 하다....
#근데 이건 사실 C++도 마찬가지라는 점....