//p.376

#include <iostream>
#include <algorithm>

int n;
int arr[501][501];

int main(){
  int temp[501];
  std::cin>>n;

  for(int i=1; i<=n; i++){
    temp[i-1]=0;
    for(int j=0; j<i; j++){
      int val;
      std::cin>>val;
      arr[i-1][j]=val;
    }
  }  

  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      if(temp[j]<arr[i-1][j]+arr[i][j])
        temp[j]=arr[i-1][j]+arr[i][j];
      if(temp[j+1]<arr[i-1][j]+arr[i][j+1])
        temp[j+1]=arr[i-1][j]+arr[i][j+1];
    }
    for(int j=0; j<=i; j++){
      arr[i][j]=temp[j];
    }
  }

  std::cout<<*std::max_element(temp,temp+n);

  return 0;
}