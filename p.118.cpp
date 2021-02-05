#include <iostream>

int main(){
    int N, M,A,B,D, temp;
    int ret=1;
    int dir[]={0,1,2,3};   
    int move_x[]={ 0, 1, 0, -1};
    int move_y[]={-1, 0, 1,  0};

    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &A, &B, &D);

    int arr[N][M];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ 
            scanf("%d", &temp);
            arr[i][j]=temp;
            if(i==0||j==0||i==N-1||j==M-1){
                arr[i][j]=1;
            }
        }
    }
    if(arr[A][B]==1){
        printf("Something wrong with input");
        return 0;
    }
    arr[A][B]=2;

    while(true){
        int na, nb;
        bool check=true;

        for(int i=0; i<4; i++){
            na=A+move_x[D];
            nb=B+move_y[D];
            
            if(arr[na][nb]==1||arr[na][nb]==2){
                D=(D-1)%4;
                if(D<0)
                    D+=4;
                continue;
            }

            if(arr[na][nb]==0){
                arr[na][nb]=2;
                A=na;
                B=nb;
                ret++;
                check=false;
                break;
            }
        }

        if(check){
            D=(D-1)%4;
            if(D<0)
                D+=4;
            A=A-move_x[D];
            B=B-move_y[D];
            if(arr[A][B]==1){
                break;
            }
        }
    }

    printf("%d", ret);
    return 0;
}