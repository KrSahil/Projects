#include<iostream>
using namespace std;
  
int main(){
 
    int x=10;
    int &y = x;

 //y++;
     x++;  // either you update x or y both are going to change

    cout<<x<<endl;
    cout<<y<<endl;
 
return 0;
}