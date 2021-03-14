#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000

struct edge{
  int price;
  int begin;
  int end;
};
bool cmp(edge a, edge b){
  if(a.price<b.price)
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

int Kruskal(){
  int ret=0;

  std::sort(edges.begin(), edges.end(), cmp);

  for(int i=0; i<E; i++){
    int a=find_root(edges[i].begin);
    int b=find_root(edges[i].end);
    if(a==b){
      continue;
    }
    ret+=edges[i].price;
    union_node(a,b);
  }

  return ret;
}

int main(){
  int ret=0;

  std::cin>>V>>E;

  for(int i=1; i<=V; i++){
    root_node[i]=i;
  }
  for(int i=0; i<E; i++){
    int begin, end, price;
    std::cin>>begin>>end>>price;
    edges.push_back({price, begin, end});
  }

  printf("%d",Kruskal());

  return 0;
}
