#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

int n,m, X, K;
std::vector<int> graph[101]; 
int distance[101];

int main(){
  std::cin>>n>>m;

  for(int i=0; i<m; i++){
    int begin, end;
    std::cin>>begin>>end;
    graph[begin].push_back(end);
  }

  std::fill(distance, distance+101, INF);
  std::priority_queue<std::pair<int, int>> pq;
  
  pq.push({0, 1});
  distance[1]=0;

  while(!pq.empty()){
    int node=pq.top().second;
    int dist=-pq.top().first;
    pq.pop();

    if(dist<distance[node])
      continue;

    for(int i=0; i<graph[node].size(); i++){
      if(dist+1<distance[graph[node][i]]){
        distance[graph[node][i]]=dist+1;
        pq.push({-dist+1, graph[node][i]});
      }
    }
  }
  
  int ret=distance[K];

  std::fill(distance, distance+101, INF);
  
  pq.push({0,K});
  distance[K]=0;

  while(!pq.empty()){
    int node=pq.top().second;
    int dist=-pq.top().first;
    pq.pop();

    if(dist<distance[node])
      continue;

    for(int i=0; i<graph[node].size(); i++){
      if(dist+1<distance[graph[node][i]]){
        distance[graph[node][i]]=dist+1;
        pq.push({-dist+1, graph[node][i]});
      }
    }
  }

  ret+=distance[X];

  printf("%d\n", ret);
}