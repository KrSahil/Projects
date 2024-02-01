#include<iostream>
using namespace std;
  
int main(){
 
    char sentence[1000];

    char temp = cin.get();

    int len=1;  // as index starts from 0 maybe
    while(temp!='#'){
        len++;
       cout<<temp;
        //update the value of tepm
        temp = cin.get();
    }
    cout<<"\nlength "<<len<<endl;
 
return 0;
}