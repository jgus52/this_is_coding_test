#include <iostream>

int main(){
    int N;
    int ret;

    scanf("%d", &N);

    if(N<3){
        ret=(N+1) * ((15*60)+(45*15));
    }
    else{
        ret=N*((15*60)+(45*15)) + 3600;
    }

    printf("%d", ret);

    return 0;
}
//brute force로 해도 되긴한데...