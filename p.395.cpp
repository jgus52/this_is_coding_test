//p.395

#include <iostream>
#include <queue>

int G,P;
int place[100001];

// int main(){
//   int ret=0;
//   std::queue<int> queue;  
//   std::cin>>G>>P;
  
//   for(int i=1; i<=G; i++){
//     place[i]=0;
//   }

//   for(int i=0; i<P; i++){
//     int place_num;
//     std::cin>>place_num;
//     queue.push(place_num);
//   }

//   while(!queue.empty()){
//     int x=queue.front();
//     bool check=false;//false라고 명시해야 되네?

//     queue.pop();
    
//     for(int i=x; i>=1; i--){
//       if(place[i]==0){
//         place[i]=1;
//         check=true;
//         ret++;
//         break;
//       }
//     }
//     if(!check){
//       break;
//     }
//   }

//   std::cout<<ret;

//   return 0;
// }
//이렇게 하면 시간복잡도가 n^2라 안 될 듯;
/////////////////////////////////////////

int find_parent(int arr[], int x){
  if(arr[x]!=x){
    arr[x]=find_parent(arr, arr[x]);
  }
  return arr[x];
}
void union_parent(int arr[], int a, int b){
  a=find_parent(arr, a);
  b=find_parent(arr, b);

  if(a<b)
    arr[b]=a;
  else
    arr[a]=b;
}

int main(){
  int ret=0;
  std::queue<int> queue;  
  std::cin>>G>>P;
  
  for(int i=0; i<=G; i++){
    place[i]=i;
  }

  for(int i=0; i<P; i++){
    int place_num;
    std::cin>>place_num;
    queue.push(place_num);
  }

  while(!queue.empty()){
    int x=queue.front();
    queue.pop();
    
    x=find_parent(place, x);
    if(x==0)
      break;
    union_parent(place, x, x-1);
    ret++;
  }

  std::cout<<ret;

  return 0;
}