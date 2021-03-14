//p.368

#include <iostream>
#include <vector>

int N;
std::vector<int> v;

int searchFixedPt(std::vector<int> v, int begin, int end){
  if(begin>end)
    return -1;

  int mid=(begin+end)/2;

  if(v[mid]==mid)
    return v[mid];
  if(v[mid]<mid)
    return searchFixedPt(v, mid+1, end);
  else if(v[mid]>mid)
    return searchFixedPt(v, begin, mid-1);
}

int main(){
  std::cin>>N;

  for(int i=0; i<N; i++){
    int val;
    std::cin>>val;
    v.push_back(val);
  }

  std::cout<<searchFixedPt(v,0, N-1);

  return 0;
}