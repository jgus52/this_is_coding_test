#include <iostream>
#include <algorithm>

int data_list[500];
int n;

void exchange(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quick_sort(int arr[], int s, int e){
    if(s>=e)
        return;
    
    int bottom=s+1;
    int top=e;

    while(bottom<=top){
        while(arr[bottom]<=arr[s] && bottom<=e)
            bottom++;
        while(arr[top]>=arr[s] && top>s)
            top--;
        
        if(bottom>top){
            exchange(&arr[s], &arr[top]);  
        }
        else
            exchange(&arr[top], &arr[bottom]);
    }
    quick_sort(arr, s, top-1);
    quick_sort(arr, top+1, e);
}

int main(){
    int temp;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        data_list[i]=temp;
    }

    std::sort(data_list, data_list+n);

    for(int i=n-1; i>=0; i--){
        printf("%d ",data_list[i]);
    }

    return 0;
}