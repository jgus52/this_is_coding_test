n=int(input())
n_arr=list(map(int, input().split()))
m=int(input())
m_arr=list(map(int, input().split()))

def binary_search(list ,start, end, target):
  while(start<=end):
    mid=(start+end)//2
    if(list[mid]==target):
      return mid
    if(list[mid]>target):
      end=mid-1
    else:
      start=mid+1
  
  return -1

n_arr.sort()

for i in m_arr:
  if binary_search(n_arr, 0, n-1, i) != -1:
    print("yes", end=' ')
  else:
    print("no", end=' ')
