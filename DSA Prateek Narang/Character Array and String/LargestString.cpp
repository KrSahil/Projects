#include<iostream>
using namespace std;

//Read N strings and print the largest string. Each string can have upto 1000 characters
  
int main(){
    int n;
    cout<<"How many sentences you want to print"<<endl;
    cin>>n;

    char sentence[1000];

    while (n--){
        cin.getline(sentence,1000);
        cout<<sentence<<endl;
    }
    //error explaine in note book
     
 
return 0;
}