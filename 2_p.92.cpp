#include <iostream>
int n, times, k;

int big_num(int arr[]){
    int a, b=-1;
    int ret=0;
    int temp_times=times;

    for(int i=0; i<n; i++){
        if(arr[i]>a){
            b=a;
            a=arr[i];
        }
        else if(arr[i]>b){
            b=arr[i];
        }
    }
    
    while(temp_times-k-1>=0){
        ret += k*a+b;
        temp_times-=k+1;
    }
    if(temp_times>0)
        ret += temp_times*a;

    return ret;
    
}

int main(){
    int num_list[1000];
    int temp;

    scanf("%d", &n);
    scanf("%d", &times);
    scanf("%d", &k);

    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        num_list[i]=temp;
    }

    printf("%d", big_num(num_list));

    return 0;
}