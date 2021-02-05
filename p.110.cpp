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
    //������ �󸶳� ������ �� ���� �׳� string���� �ް� ���鿡���� �ƹ� ó���� ���� �ϸ� �ȴ�.
    //���̽����� �ϸ� �׳� split()���� ���������� ������ �� �޾Ƽ� �װ� �� ���ϱ� �ѵ� �� c++�� �� �� �̷��� �ϴ� �� ���� �� ����.
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