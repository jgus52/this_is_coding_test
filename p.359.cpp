#include <iostream>
#include <vector>
#include <algorithm>

int N;
struct Student {
  std::string name;
  int kor;
  int eng;
  int math;
};

bool compare_alphabet(const Student& s1, const Student& s2){
  return s1.name<s2.name;
  //작은 게 앞으로 와야겠지요?
}
bool compare(const Student& s1, const Student& s2){
  if(s1.kor==s2.kor){
    if(s1.eng==s2.eng){
      if(s1.math==s2.math){
        return s1.name<s2.name;
      }
      else return s1.math>s2.math;
    }
    else
      return s1.eng<s2.eng;
  }

  else
    return s1.kor>s2.kor;
}

int main(){
  std::vector<Student> arr;

  std::cin>>N;

  for(int i=0; i<N; i++){
    Student st;
    std::cin>>st.name>>st.kor>>st.eng>>st.math;
    arr.push_back(st);
  }

  std::sort(arr.begin(), arr.end(), compare);

  for(int i=0; i<N; i++){
    std::cout<<arr[i].name<<std::endl;
  }

  return 0;
}