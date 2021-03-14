#include <iostream>

std::string n;

int main(){
  std::cin>>n;

  int ret=n[0]-'0';

  for(int i=1; i<n.size(); i++){
    if(n[i]<='1' || ret<=1){
      ret+=n[i]-'0';
    }
    else ret=ret * (n[i]-'0');
  }

  printf("%d\n", ret);

  return 0;
}