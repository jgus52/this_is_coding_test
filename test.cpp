//p.395

#include <iostream>
#include <queue>

int G,P;
int place[100001];

int main(){
  int ret=0;
  std::queue<int> queue;  
  std::cin>>G>>P;
  
  for(int i=1; i<=G; i++){
    place[i]=0;
  }

  for(int i=0; i<P; i++){
    int place_num;
    std::cin>>place_num;
    queue.push(place_num);
  }

  while(!queue.empty()){
    int x=queue.front();
    bool check=false;//false라고 명시해야 되네?

    queue.pop();
    
    for(int i=x; i>=1; i--){
      if(place[i]==0){
        place[i]=1;
        check=true;
        ret++;
        break;
      }
    }
    if(!check){
      break;
    }
  }

  std::cout<<ret;

  return 0;
}