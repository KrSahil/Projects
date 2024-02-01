#include<iostream>
using namespace std;
  
int main(){
 
    char sentence[1000];

    char temp = cin.get();
    int len=0;
    //storing char in a array
  while(temp!='\n'){
        
    sentence[len++]= temp;
        temp = cin.get();
    }
    //sentence[len]='\0';
    cout<<"\nlength "<<len<<endl;
    cout<<sentence;
    
 
return 0;
}