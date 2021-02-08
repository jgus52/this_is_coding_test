#include <iostream>
#include <stack>

int arr[1000][1000];
int n,m;

bool DFS(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m)
        return false;
    if(arr[x][y]==0){
        arr[x][y]=1;
        DFS(x+1,y);
        DFS(x-1,y);
        DFS(x,y+1);
        DFS(x,y-1);
        return true;
    }
    return false;
}
int main(){
    int ret=0; int temp;
    
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &temp);
            arr[i][j]=temp;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(DFS(i,j)==true){
                ret++;
            }
        }
    }

    printf("%d", ret);

    return 0;
}