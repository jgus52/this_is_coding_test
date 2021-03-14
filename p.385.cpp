#include <iostream>
#include <vector>
#include <queue>

int N, M;
std::vector<std::pair<int,int>> busline[101];
int price[101];

int main(){
  std::cin>>N>>M;
  for(int i=0; i<M; i++){
    int from, to, price;
    std::cin>>from>>to>>price;
    busline[from].push_back({to, price});
  }

  for(int i=1; i<=N; i++){
    std::queue<int> q;
    q.push(i);

    for(int j=1; j<=N; j++){
      price[j]=-1;
    }
    price[i]=0;

    while(!q.empty()){
      int x=q.front();
      q.pop();

      for(int j=0; j<busline[x].size(); j++){
        if(price[busline[x][j].first]==-1 || price[busline[x][j].first]>price[x]+busline[x][j].second){
          price[busline[x][j].first]=price[x]+busline[x][j].second;
          q.push(busline[x][j].first);
        }
      }
    }

    for(int j=1; j<=N; j++){
      if(price[j]==-1)
        std::cout<<"0 ";
      else std::cout<<price[j]<<" ";
    }std::cout<<std::endl;
  }

  return 0;
}