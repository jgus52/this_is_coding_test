#include <iostream>

int main(){
    int count=0;
    int N, K;

    scanf("%d", &N);
    scanf("%d", &K);

    while(N!=1){
        if(N%K==0){
            N=N/K;
            count++;
        }
        else{
            N=N-1;
            count++;
        }
    }

    printf("%d", count);

    return 0;
}