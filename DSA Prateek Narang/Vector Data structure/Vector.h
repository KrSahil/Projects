//line 5
//by using template we can create vector of strin, boolean, student


template<typename T> // here T is a user defined datatype
// this makes code more generic
class Vector{
     //Data member

    T *arr; //array pointer that will point to a memory location
    int cs;   //current size
    int ms;   //max size     
     
     //Method, Constructor, Destructor
public:
    Vector(int max_size=1){ //default max size is 1 and we can also take input from the user
        cs=0;
        ms=max_size;
        arr= new T[ms];
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
    T front(){
        return arr[0];
    }

    T back(){
        return arr[cs-1];
    }

    T at(int i){
        return arr[i];
    }

    int size(){
        return cs;
    }

    int capacity(){
        return ms;  //max size is the capacity of the vector
    }


    T operator[](int i){
        return arr[i];
    }
    


};