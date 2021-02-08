#include <iostream>
#include <vector>
#include <algorithm>

typedef struct data{
    std::string name;
    int score;

    data(std::string name, int score){
        this->name=name;
        this->score=score;
    }
    bool operator <(data compared){
        return this->score < compared.score;
    }

}data;

int n;

std::vector<data> v;

int main(){
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        std::string name;
        int score;
        std::cin>>name>>score;
        v.push_back(data(name,score));
    }

    std::sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        std::cout<<v[i].name<<" ";
    }

    return 0;

}

//operator관련된 건 하도 안 써먹었더니 다 까먹은 거 같다.
//다시 한 번 볼 것