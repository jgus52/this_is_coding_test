#include <iostream>
#include <queue>
#include <vector>
#define MAX 500

int V,E;
std::vector<int> node[MAX+1];
int getin[MAX+1];


void topological_sort(int arr[]){
  int index=0;
  std::queue<int> q;

  for(int i=1; i<=V; i++){
    if(getin[i]==0)
      q.push(i);
  }
  
  std::cout<<std::endl;

  while(!q.empty()){
    int x=q.front();
    q.pop();
    arr[index]=node[x].front();
    index++;

    for(int i=0; i<node[x].size(); i++){
      getin[node[x][i]]-=1;
      if(getin[node[x][i]]==0){
        q.push(node[x][i]);
      }
    }
  }
}

int main(){
  int ret[MAX+1];

  std::cin>>V;

  for(int i=1; i<=V; i++)
    getin[i]=0;
  
  for(int i=0; i<V; i++){
    for(int j=0; j<V+1; j++){
      int x;
      std::cin>>x;
      if(x==-1){
        break;
      }
      node[i].push_back(x);
    }
    getin[i]=node[i].size()-1;
  }


  topological_sort(ret);

  for(int i=0; i<V; i++){
    printf("%d ", ret[i]);
  }
}
