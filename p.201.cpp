#include <iostream>
#include <algorithm>
#include <vector>

#define ELEMENT int

int n,m;
std::vector<ELEMENT> arr;

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

int height(int start, int end){
  if(start>end){
    return start;
  }
  
  int nh=(start+end)/2;
  int sum=0;

  for(int i=0; i<n; i++){
    sum+=arr[i]-nh;
  }

  if(sum<m){
    return height(start, nh-1);
  }
  else{
    return height(nh+1, end);
  }
}

int main(){
  int temp;

  scanf("%d%d", &n, &m);

  for(int i=0; i<n; i++){
    scanf("%d", &temp);
    arr.push_back(temp);
  }

  std::sort(arr.begin(), arr.end());


  int h=height(0, n-1);
  
  printf("%d", h);
}