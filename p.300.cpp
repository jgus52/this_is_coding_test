#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100000

struct edge{
  int cost;
  int begin;
  int end;
};
bool cmp(edge a, edge b){
  if(a.cost<b.cost)
    return true;
  return false;
}

int V,E;
std::vector<edge> edges;
int root_node[MAX+1];

int find_root(int node){
  if(root_node[node]!=node){
    root_node[node]=find_root(root_node[node]);
  }
  return root_node[node];
}

void union_node(int node1, int node2){
  node1=find_root(node1);
  node2=find_root(node2);
  if(node1<node2)
    root_node[node2]=node1;
  else
    root_node[node1]=node2;
}

int main(){
  std::cin>>V>>E;

  for(int i=0; i<E; i++){
    int begin, end, cost;
    std::cin>>begin>>end>>cost;
    edges.push_back({cost, begin, end});
  }

  std::sort(edges.begin(), edges.end(),cmp);

  int last, ret=0;
  
  for(int i=1; i<=V; i++){
    root_node[i]=i;
  }
  for(int i=0; i<E; i++){
    int a=find_root(edges[i].begin);
    int b=find_root(edges[i].end);
    if(a==b){
      continue;
    }
    else{
      ret+=edges[i].cost;
      last=edges[i].cost;
      union_node(a,b);
    }
  }

  printf("%d\n", ret-last);
}