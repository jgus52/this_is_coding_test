#include <iostream>
#include <algorithm>

int num_list[100][100];
int n,m;

int main(){
    int temp;
    int smallest[100];

    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &temp);
            num_list[i][j]=temp;
        }
    }

    for(int i=0; i<n; i++){
        smallest[i]=*std::min_element(num_list[i], num_list[i]+m);
    }

    printf("%d", *std::max_element(smallest, smallest+n));

    return 0;
}

//공간복잡도를 이렇게 사용할 필요없다.
//어차피 가장 작은 값들만 추출하면 되니까 굳이 이중배열로 안 만들어도
//한 라인 받고 최소 추출하여 smallest에 넣고 다시 하면 된다.

// #include <iostream>
// #include <algorithm>

// int num_list[100];
// int n,m;

// int main(){
//     int temp;
//     int smallest[100];

//     scanf("%d", &n);
//     scanf("%d", &m);
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             scanf("%d", &temp);
//             num_list[i]=temp;
//         }
//         smallest[i]=*std::min_element(num_list, num_list+m);
//     }

//     printf("%d", *std::max_element(smallest, smallest+n));

//     return 0;
// }

//이런식으로 햐면 공간 복잡도 면에서도 더 이득이고 작성하는 것 자체도 어렵지 않다.