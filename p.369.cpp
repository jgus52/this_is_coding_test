//p.360

#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<int> homes;

int main(){
  int ret;
  
  std::cin>>n;

  for(int i=0; i<n; i++){
    int val;
    std::cin>>val;
    homes.push_back(val);
  }

  std::sort(homes.begin(), homes.end());

  if(homes.size()%2==0)
    ret=homes[homes.size()/2-1];
  else
    ret=homes[homes.size()/2];
  
  std::cout<<ret;

  return 0;  
}