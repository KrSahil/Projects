#include<iostream>
using namespace std;

int getIthBit(int n, int i){
    int mask = (1<<i);
    return (n & mask) >0 ? 1 : 0;

}

void clearIthBit(int &n,int i){
    int mask = ~(1<<i);
    n = n & mask; //sets the right value
}

void updateIntBit(int n, int i, int v){
    //combine setBit and Ith bit
    clearIthBit(n,i);
    int mask = (v<<i);
    n = n|mask; //
}
  
int main(){
 
     int n=13;
     int i;
     cin>>i;

     updateIntBit(n,i,1);

     cout<<n;
 
return 0;
}