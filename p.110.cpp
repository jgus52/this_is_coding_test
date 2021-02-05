#include <iostream>

int N;

int main(){
    char char_list[4]={'L', 'R', 'U', 'D'};
    int move_x[4]={-1, 1, 0, 0};
    int move_y[4]={0, 0, -1, 1};
    std::string plans;
    int x=1; int y=1;
    
    scanf("%d", &N);
    fflush(stdin);
    std::getline(std::cin, plans);
    //라인을 얼마나 받을지 모를 때는 그냥 string으로 받고 공백에서는 아무 처리도 없게 하면 된다.
    //파이썬으로 하면 그냥 split()으로 조져버리면 공백을 안 받아서 그게 더 편하긴 한데 뭐 c++로 할 떈 이렇게 하는 게 좋을 것 같다.
    for(int i=0; i<plans.size(); i++){
        char c=plans[i];
        int mx, my;

        for(int j=0; j<4; j++){
            if(c==char_list[j]){
                mx = x + move_x[j];
                my = y + move_y[j];
            }
        }

        if(mx<1 || my<1 || mx>N || my>N)
            continue;
        
        x=mx; y=my;
    }

    printf("%d %d", y, x);

   return 0; 
}