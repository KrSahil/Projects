#include<iostream>
using namespace std;

class Vector{
     //Data member

    int *arr; //array pointer that will point to a memory location
    int cs;   //current size
    int ms;   //max size     
     
     //Method, Constructor, Destructor
public:
    Vector(int max_size=1){ //default max size is 1 and we can also take input from the user
        cs=0;
        ms=max_size;
        arr= new int[ms];
    }

    void push_back(int d){
        //Two Cases
        if(cs==ms){
            //Create a new array and delete the old one and doubel the capacity
            int *oldArr = arr;
            ms = 2*ms;
            arr = new int[ms]; //creates new array
            //copy the elements
            for (int i=0;i<cs;i++){
                   arr[i]=oldArr[i]; 
            
            
        }
        //Delete the old arr
        delete oldArr;
       
    }
     //when the array is not full
        arr[cs]= d;
        cs++;
}
    void pop_back(){
          if(cs>=0){
              cs--;
          }
    }

    //front,back, at[i]
    int front(){
        return arr[0];
    }

    int back(){
        return arr[cs-1];
    }

    int at(int i){
        return arr[i];
    }

    int size(){
        return cs;
    }

    int capacity(){
        return ms;  //max size is the capacity of the vector
    }

    


};

  
int main(){
    Vector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout<<v.front()<<endl;
    cout<<v.back()<<endl;

    cout<<v.at(3)<<endl;

    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl<<endl;

    //print all the element of the vector
    for (int i=0; i<v.size();i++){
        cout<<v.at(i)<<",";
    }

 
return 0;
}