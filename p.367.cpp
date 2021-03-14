#include <iostream>

int N,X;
int arr[1000000];
int ret=0;

void binary_search(int X, int start, int end){
  if(start==end){
    if(arr[start]==X) ret++;  
    return;
  }

  int mid=(start+end)/2;
  if(X==arr[mid]){
    ret++;
    binary_search(X,start,mid-1);
    binary_search(X,mid+1, end);
  }
  else if(X<arr[mid]){
    binary_search(X, start, mid-1);
  }
  else{
    binary_search(X, mid+1, end);
  }
}

int main(){
  std::cin>>N>>X;
  for(int i=0; i<N; i++){
    int x;
    std::cin>>x;
    arr[i]=x;
  }

  binary_search(X, 0, N);

  printf("%d", ret);
}