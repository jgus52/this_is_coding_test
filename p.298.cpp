#include <iostream>
#define MAX 100000
int M,N;
int root[MAX+1];

int find_root(int node){
  if(root[node]!=node)
    root[node]=find_root(root[node]);
  return root[node];
}

void union_node(int node1, int node2){
  node1=find_root(node1);
  node2=find_root(node2);
  if(node1<node2){
    root[node2]=node1;
  }
  else{
    root[node1]=node2;
  }
}

int main(){
  std::cin>>N>>M;

  for(int i=1;i<=N;i++){
    root[i]=i;
  }

  for(int i=0; i<M;i++){
    int a,team1,team2;

    std::cin>>a>>team1>>team2;
    if(a==0){
      union_node(team1, team2);
    }
    else{
      if(find_root(team1)==find_root(team2))
        printf("YES\n");
      else
        printf("NO\n");
    }
  }


}

