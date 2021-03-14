//p.386
#include <iostream>
#include <vector>
#include <algorithm>

int n,m;
int arr[501][501];
const int INF=1e9;

int main(){
  std::cin>>n>>m;

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      arr[i][j]=INF;

  for(int i=0; i<m; i++){
    int head, arrive;
    std::cin>>head>>arrive;
    arr[head][arrive]=1;
  }

  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      for(int k=1; k<=n; k++){
        arr[j][k]=std::min(arr[j][k], arr[j][i]+arr[i][k]);
      }
    }
  }

  int ret=0;

  for(int i=1; i<=n; i++){
    int cnt=0;
    for(int j=1; j<=n; j++){
      if(arr[i][j]!=INF || arr[j][i]!=INF)
        cnt++;      
    }
    if(cnt==n-1){
      ret++;
    }
  }

  std::cout<<ret;
  return 0;
}