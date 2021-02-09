#include <iostream>
#include <algorithm>

#define ELEMENT int

int n,m;
int n_arr[1000000],m_arr[1000000];

int binary_search(ELEMENT arr[], int start, int end, int target){
  //return index of target that we finding;
  //-1 for none
  int mid=(start+end)/2;

  if(start>end)
    return -1;
  if(arr[mid]==target)
    return mid;
  
  if(arr[mid]<target){
    return binary_search(arr, mid+1, end, target);
  }
  else{
    return binary_search(arr, start, mid-1, target);
  }
}

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &n_arr[i]);
  }
  scanf("%d", &m);
  for(int i=0; i<m; i++){
    scanf("%d", &m_arr[i]);  
  }

  std::sort(n_arr, n_arr+n);

  for(int i=0; i<m; i++){
    if(binary_search(n_arr, 0, n-1, m_arr[i])>=0){
      printf("yes ");
    }
    else{
      printf("no ");
    }
  }

  return 0;
}