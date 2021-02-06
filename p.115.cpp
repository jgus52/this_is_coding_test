#include <iostream>


int main(){
    int row[8]={1, 2, 3, 4, 5, 6, 7, 8};
    int column[8]={1,2,3,4,5,6,7,8};
    int move_x[8]={2,  2, -2, -2, 1, -1,  1, -1};
    int move_y[8]={1, -1,  1, -1, 2,  2, -2, -2};


    int r, c, ret;
    char n;
    scanf("%c%d", &n, &r);

    c=(int)(n-'a'+1);
    ret=0;
 
    for(int i=0; i<8; i++){
        int moved_c, moved_r;
        moved_c=c+move_x[i];
        moved_r=r+move_y[i];

        if((moved_c>=1 && moved_c<=8)&& (moved_r>=1 && moved_r<=8))
            ret++;
    }

    printf("%d", ret);

    return 0;
}