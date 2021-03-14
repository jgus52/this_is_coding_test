#include <iostream>
#include <vector>
#define MAX 10000


int V,E;
std::vector<std::pair<int, int>> graph[MAX];
int root_node[MAX];

int find_root(int node){
  if(root_node[node]!=node){
    root_node[node]=find_root(root_node[node]);
    //여기서 업데이트를 안 해주고 return으로 빼기만 하면 결론적으로는 root_node 배열에 업데이트가 되지 않는다.
  }
  return root_node[node];
}

void union_node(int node1, int node2){
  node1=find_root(node1);
  node2=find_root(node2);
  //근본적으로 가장 상위에 있는 노드를 이어주는 역할이 필요하기 때문에...
  if(node1<node2)
    root_node[node2]=node1;
  else
    root_node[node1]=node2;
}

int main(){
  std::cin>>V>>E;

  for(int i=1; i<=V; i++){
    root_node[i]=i;
  }
  for(int i=0; i<E; i++){
    int begin, end;
    std::cin>>begin>>end;
    union_node(begin, end);
  }

  for(int i=1; i<=V; i++)
    printf("%d ",find_root(i));
    //최종적으로 마지막으로 한 번 더 돌려야 여기서 원하는 결과를 얻을 수 있다.
    //모든 엣지를 다 연결해야 제대로 된 최종 루트노드를 찾을 수 있지...바보야...

  return 0;
}