#include<iostream>
using namespace std;
  
int main(){
 
    char sentence[1000];

    char temp = cin.get();

    int len=1;
    while(temp!='\n'){
        len++;
        cout<<temp;
        //update the value of tepm
        temp = cin.get();
    }
    cout<<"\nlength "<<len<<endl;
 
return 0;
}

//additional check, we should chech our len doesn't exceeds the sectenc arry or it will
//cause fragmentation error