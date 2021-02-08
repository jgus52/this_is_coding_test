#include <iostream>
#include <algorithm>

int A[100000], B[100000];
int n,k;

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
    std::cin>>n>>k;

    for(int i=0; i<n; i++){
        int temp;
        std::cin>>temp;
        A[i]=temp;
    }
    for(int i=0; i<n; i++){
        int temp;
        std::cin>>temp;
        B[i]=temp;
    }

    quick_sort(A, 0, n-1);
    quick_sort(B, 0, n-1);

    int sum=0;
    for(int i=0; i<n; i++){
        sum+=A[i];
    }

    for(int i=0; i<k; i++){
        if(A[i]<B[n-1-i]){
            sum+=B[n-1-i]-A[i];
        }
        else{
            break;
        }
    }
    

    printf("%d", sum);
}