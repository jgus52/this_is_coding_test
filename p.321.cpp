#include <iostream>

int N;

int getDigit(int N){
  int ret=1;

  while(N>10){
    N=N/10;
    ret++;
  }

  return ret;
}
int sumDigit(int N){
  int ret=0;
  while(N>10){
    ret+=N - (N/10)*10;
    N=N/10;
  }
  ret+=N;

  return ret;
}

int main(){
  std::cin>>N;

  int digit=getDigit(N);
  int divider=1,right,left;
  
  for(int i=0; i<digit/2; i++){
    divider=divider*10;
  }
  right=N/divider;
  left=N - right*divider;

  if(sumDigit(right)==sumDigit(left)) printf("LUCKY");
  else printf("READY");

  return 0;
}

//string으로 하고 '0'을 빼면 되는구나
// int main(){
//   string str;
//   int sum=0;

//   std::cin>>str;

//   for(int i=0; i<str.size()/2; i++){
//     sum+=str[i]-'0';  
//   }
//   for(int i=str.size()/2; i<str.size(); i++){
//     sum-=str[i]-'0';
//   }

//   if(sum==0) printf("LUCKY");
//   else printf("READY");
// }