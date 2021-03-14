#include <iostream>
#include <vector>

int N, M;
int line[501][501];
int root[501];

int main(){
  std::vector<int> q;
  
  std::cin>>N>>M;
  for(int i=1; i<=N; i++){
    root[i]=i;
    for(int j=1; j<=N; j++){
      int val;
      std::cin>>val;
      line[i][j]=val;
    }
  }
  
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(line[i][j]==1 && root[i]<root[j])
        root[j]=root[i];
    }
  }

  for(int i=0; i<M; i++){
    int val;
    std::cin>>val;
    q.push_back(val);
  }

  for(int i=0; i<q.size()-1; i++){
    if(root[q[i]]!=root[q[i+1]]){
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");
}