#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Car{
public:
    string id;
    int x,y;
    Car(string id,int x,int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }
   // int dist(){  //this will give us error because distance function must be constant
   int dist() const {
        return x*x + y*y; //square of the distance
    }

};

//camparison class
class carCompare{
public:
    bool operator()(const Car A,const Car B){ //to give your custom camparison comperator u have to creaete a classs like this
        return A.dist() < B.dist(); //Max heap
    }
};

void printNearestCars(vector<Car> cars,int k){
    //create a max heap of size k
    priority_queue<Car, vector<Car>, carCompare> max_heap(cars.begin(),cars.begin()+k);
    //                                                    0th car from cars.begin and end is going to be cars.begin() +k

    //iterate over the remaining cars
    for(int i=k; i<cars.size(); i++){
        auto car = cars[i];

        if(car.dist() < max_heap.top().dist()){
            //we alway pop the first element
            max_heap.pop(); //removes the root node
            max_heap.push(car);
        }
    }
    //print all the cars inside the heap they will be the smallest
    while(!max_heap.empty()){
        cout<<max_heap.top().id<<endl;
        max_heap.pop();
    }
    return;
}
  
int main(){

    int N,K;
    cin>>N>>K;

    string id;
    int x,y;

    vector<Car> cars;

    for(int i =0; i<N; i++){
        cin>>id>>x>>y;
        Car car(id,x,y);
        cars.push_back(car);
    }

    printNearestCars(cars,K);
 
return 0;
}