#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
  
int main(){
    vector<pair<string,vector<int> > > student_marks = {
        {"Rohan",{10,20,11}},
        {"Prateek",{10,21,3}},
        {"Vivek",{4,5,6}},
        {"Rijul",{10,13,20}}
    };
 
    sort(student_marks.begin(),student_marks.end());

    for(auto s : student_marks)
{
    cout<<s.first<<endl;
} 
return 0;
}