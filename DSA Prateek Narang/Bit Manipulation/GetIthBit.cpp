#include<iostream>
using namespace std;

int getIthBit(int n, int i){
    int mask = (1<<i);
    return (n & mask) >0 ? 1 : 0;

}

void clearIthBit(int &n,int i){
    int mask = ~(1<<i);
    n = n & mask;
}
  
int main(){
 
     int n=13;
     int i;
     cin>>i;

     cout<<getIthBit(n,i)<<endl;
     

     clearIthBit(n,i);
     cout<<n;
 
return 0;
}