#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

int m,n,start;
std::vector<std::pair<int,int>> graph[10001]; 
int distance[10001];

void dijkstra(int start){
  std::priority_queue<std::pair<int,int>> pq;

  pq.push({0,start});
  distance[start]=0;

  while(!pq.empty()){
    int dist=-pq.top().first;
    int node=pq.top().second;
    pq.pop();

    if(distance[node]<dist){
      continue;
    }
    
    for(int i=0; i<graph[node].size(); i++){
      int new_dist=dist+graph[node][i].second;
      if(new_dist<distance[graph[node][i].first]){
        distance[graph[node][i].first]=new_dist;
        pq.push(std::make_pair(-new_dist,graph[node][i].first));
      }
    }
  }
}
//우선순위 큐는 디폴트가 max heap이라서 -를 붙여서 넣는다.
//distance에는 양수가 들어가야 하기 때문에 처음에 pq에서 받을 때 음수를 양수로 바꿔서 받고,
//distance에 갱신할 때는 다시 -를 붙여 priority queue에서 최단거리가 top이 되도록 유지한다.

int main(){

  std::cin>>n>>m>>start;

  for(int i=0; i<m; i++){
    int begin, end, distance;
    std::cin>> begin>>end>>distance;
    graph[begin].push_back({end, distance});
  }

  std::fill(distance, distance+10001, INF);

  dijkstra(start);

  for(int i=1; i<=n; i++){
    if(distance[i]==INF){
      std::cout<<start<<" to "<<i<<" INFINITY\n";
    }
    else{
      std::cout<<start<<" to "<<i<<" "<<distance[i]<<std::endl;
    }
  }

  return 0;
}