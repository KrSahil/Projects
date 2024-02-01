
class Queue{

        int *arr;
        int cs;  //current size
        int ms;  ///max size

        int front;
        int rear;  
public:
    Queue(int default_size = 5){
        ms = default_size;
        arr = new int[ms];
        cs = 0;
        front = 0;
        rear = ms-1; 
    }

    bool full(){
        return cs==ms;
    }

    bool empty(){
        return cs==0;
    }

    void push(int data){  //it will work if queue is not full
        if(!full()){
            //take the rear to next index
            rear = (rear+1)%ms;     
            arr[rear]=data;
            cs++;
        }

    }

    void pop(){ //we can remove from the queu only if the queue is not empty
        if(!empty()){
            //take the front pointer forward
            front = (front+1)%ms;
            cs--;
        }
    }

    int getFront(){
        return arr[front];
    }


};