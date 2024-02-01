#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Point class 
class Point{
    public:
        int x;
        int y;

        Point(){

        }

        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
};  

//Comparator class
class Compare{
    public:
        bool operator()(const Point p1, const Point p2){
            if(p1.x==p2.x){
                return p1.y < p2.y;
            }
            return p1.x < p2.x;
        }
        //this may be wrong because 2,4 and 2,3 in both of the x cordinates are same
        //so we added if before return
};

int count_rectangles(vector<Point> points){
    //1st step : Insert all the Points in the set
    
    //set<Point> s; // ?? but u may ask , does set now to insert point
    set<Point,Compare> s;


    for(Point p:points){
        s.insert(p); //any give point in the vector is now inserted in the set
            // ?? but u may ask , does set now to insert point
    }

    int ans = 0;

    //2nd step : Main logic
    //brute force for 2 points and for other two points LookUp
    for(auto it = s.begin(); it != prev(s.end()); it++){ //s.end(), here if we modify it to "prev(s.end())" it will bring us to second last element
        for(auto jt = next(it); jt != s.end(); jt++ ){ //next(it) == it+1

            Point p1 = *it; //Point p1 can be accessed by derefrencing it
            Point p2 = *jt;

            //small check
            /*
                        p2  (x,_)
                        .
                        .
                        .
                (x,y) p1. . . . . . . . p2 (_,y)
                      we dont want such point , elements should not be in same x and y

            */
           if(p2.x==p1.x || p2.y==p1.y){
                continue;
           }

           //P3 and P4
           Point p3(p1.x,p2.y);  //point p3 should be same as (p1.x,p2.y)
           Point p4(p2.x,p1.y);  //point p4 should be same as (p2.x,p1.y)

           //LookUp
           if(s.find(p3) != s.end() && s.find(p4) != s.end()){
            ans += 1;
           }
        }
    }
    return ans/2;  //Each rectangle will be computed twic so ans/2;

}
  
int main(){

    int N;
    cin>>N;

    int x,y;

    vector<Point> points; //vector of points that will stor all the N points

    for(int i = 0; i < N; i++){
        cin>>x>>y;
        Point p(x,y); //for each input x and y ,i create a point (x,y)
        points.push_back(p); //push into vector
    } 

    cout<<count_rectangles(points);
 
return 0;
}