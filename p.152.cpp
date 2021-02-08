#include <iostream>
#include <queue>

int arr[200][200];
int n, m;
std::queue<std::pair<int,int>> queue;//pair을 써서 해결하는게 안 쓰는 것보다 덜 귀찮을지도?
//큐를 안 쓰고 해결하려면 최솟값만 넣어야 되는데 1로 판별하기 때문에 귀찮을 것 같다.
//큐를 안 쓰면 distnace를 두고 해결하는 게 맞을 듯.


int main(){
    int temp;
    int move_x[]={1,0,-1,0};
    int move_y[]={0,1,0,-1};
    scanf("%d",&n);
    scanf("%d", &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &temp);//이렇게 해서 정수 하나씩 받을 수 있다는 점을 기억합시다.
            arr[i][j]=temp;
        }
    }

    queue.push({0,0});

    while(!queue.empty()){
        int x,y,nx, ny;
        
        x=queue.front().first;
        y=queue.front().second;
        queue.pop();

        for(int i=0; i<4; i++){
            nx=x+move_x[i];
            ny=y+move_y[i];

            if(nx<0 || ny<0 || nx>=m || ny>=m || arr[nx][ny]==0)
                continue;
            if(arr[nx][ny]==1){
                arr[nx][ny]=arr[x][y]+1;
                queue.push({nx,ny});
            }
        }
  }

    printf("%d", arr[n-1][m-1]);

    return 0;
}


//큐로 안하고 하려면 이런식으로?, 큐랑 반복횟수는 비슷할 거 같긴 한데 정확히는 모르겠다.
#include <iostream>
#include <queue>
const int INF=99999;

int arr[200][200];
int distance[200][200];
int n, m;

void BFS(int x, int y, int d){
    
    if(x<0||y<0||x>=n||y>=m||arr[x][y]==0)
        return;
    if(arr[x][y]==1){
        if(distance[x][y]>d){
            distance[x][y]=d+1;
            BFS(x+1, y, distance[x][y]);
            BFS(x-1, y, distance[x][y]);
            BFS(x, y+1, distance[x][y]);
            BFS(x, y-1, distance[x][y]);
        }
    }
}  

int main(){
    int temp;
    scanf("%d",&n);
    scanf("%d", &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &temp);//이렇게 해서 정수 하나씩 받을 수 있다는 점을 기억합시다.
            arr[i][j]=temp;
            distance[i][j]=INF;
        }
    }
    
    BFS(0,0,arr[0][0]);
    printf("\n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ",distance[i][j]);
        }printf("\n");
    }
    
    printf("\n%d", distance[n-1][m-1]-1);

    return 0;
}
