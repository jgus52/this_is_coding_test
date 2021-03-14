//p.322

#include <iostream>
#include <algorithm>

void sort_s(std::string s, int begin, int end){
  if(begin>=end) return;

  char x=s[begin];
  int left=begin+1, right=end;
  while(left<=right){
    while(s[left]<=x && left<=end)
      left++;
    while(s[right]>=x && right>begin)
      right--;

    if(left>right){
      char temp=x;
      s[begin]=s[right];
      s[right]=temp;
    }
    else{
      char temp=s[left];
      s[left]=s[right];
      s[right]=temp; 
    }
  }
  sort_s(s, begin, right-1);
  sort_s(s, right+1, end);
}

int main(){
  std::string s;
  int ret=0;
  
  s="K1KA5CB7";

  sort_s(s, 0, s.size()-1);

  for(int i=0; i<s.size(); i++){
    if(s[i]<='9'&&s[i]>='0'){
      ret+=s[i]-'0';
    }
    else std::cout<<s[i];
  }
  std::cout<<ret;

  return 0;
}