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

//�������⵵�� �̷��� ����� �ʿ����.
//������ ���� ���� ���鸸 �����ϸ� �Ǵϱ� ���� ���߹迭�� �� ����
//�� ���� �ް� �ּ� �����Ͽ� smallest�� �ְ� �ٽ� �ϸ� �ȴ�.

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

//�̷������� ��� ���� ���⵵ �鿡���� �� �̵��̰� �ۼ��ϴ� �� ��ü�� ����� �ʴ�.