#include <iostream>
#include <stack>
#include <algorithm>

const int SIZE=100000;
int N;
int arr[SIZE];

int main(){
  std::cin>>N;
  for(int i=0; i<N; i++){
    int val;
    std::cin>>val;
    arr[i]=val;
  }

  std::sort(arr, arr+N);
  int ret=0;
  std::stack<int> group;

  for(int i=0; i<N; i++){
    group.push(arr[i]);
    if(group.top() == group.size()){
      ret++;
      while(!group.empty())
        group.pop();
    }
  }

  printf("%d\n", ret);

  return 0;
}