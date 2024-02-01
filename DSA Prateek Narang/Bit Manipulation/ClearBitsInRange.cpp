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

void clearLastIBits(int &n, int i){

     int mask = (~0 << i);  //~0 == -1
   n = n & mask;
}

void clearBitsInRange ( int &n, int i, int j){
     int a = (~0)<<(j+1);
     int b = (1<<i)-1;
    int mask = a|b ;
    n = n & mask;
}



  
int main(){
 
     int n=15;
     int i,j;
     cin>>i>>j;

     clearBitsInRange(n,i,j);

     cout<<n;
 
return 0;
}