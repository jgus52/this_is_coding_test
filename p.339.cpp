#include <iostream>
#include <vector>
#include <queue>

std::vector<int> graph[300001];
int N,M,K,X;
int dist[300001];

int main(){
  std::cin>>N>>M>>K>>X;
  
  for(int i=0; i<M; i++){
    int begin, end;
    std::cin>>begin>>end;
    graph[begin].push_back(end);
  }

  for(int i=1; i<=N; i++)
    dist[i]=-1;

  std::queue<int> q;

  q.push(X);
  dist[X]=0;

  while(!q.empty()){
    int start=q.front();
    q.pop();

    for(int i=0; i<graph[start].size(); i++){
      if(dist[graph[start][i]]==-1){
        q.push(graph[start][i]);
        dist[graph[start][i]]=dist[start]+1;
      }
    }
  }

  bool check;
  for(int i=1; i<=N; i++){
    if(dist[i]==K){
      printf("%d ", i);
      check=true;
    }
  }
  if(!check){
    printf("-1\n");
  }
  return 0;
}