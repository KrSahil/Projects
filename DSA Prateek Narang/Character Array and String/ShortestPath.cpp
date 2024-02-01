#include<iostream>
using namespace std;
  
int main(){
 
    char route[10000];
    cin.getline(route,1000);


    int x=0;
    int y=0;
    for (int i=0; route[i]!='\0'; i++){
        switch (route[i])
        {
        case 'N': y++;
            break;

        case 'S': y--;
            break;

        case 'E': x++;
            break;
        
        case 'W': x--;
            break;
        
        }
    }
    cout<<"Final x and y is "<<x<<" ,"<<y<<endl;
    //converting x any y in terms of directons
    if(x>=0 and y>=0){ //1st quadrant
        while(y--){
            cout<<"N";
        }
        while(x--){
            cout<<"E";
        }
    }
    //like wise we need to find it for all the quadrants
  /*  else if (x<=0 and y<=0){
        while (y--){
            cout<<"";
        }
        while (y--){
            cout<<"";
        }
    }
*/

return 0;
}