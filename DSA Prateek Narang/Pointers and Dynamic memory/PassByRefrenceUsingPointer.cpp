#include<iostream>
using namespace std;


/*  //this is not going to work as it is pass by value
void watchVideo(int views){
    //watch vido should increament view count by 1

    //views=views+1;
    views +=1;


}

int main(){

    int views = 100;

    watchVideo(views);

    cout<< views<<endl;
 
return 0;
}
*/

void watchVideo(int *viewsPtr){
    //watch vido should increament view count by 1

   // *viewsPtr +=1;
   *viewsPtr= *viewsPtr+1; 
}
  
int main(){

    int views = 100;

    watchVideo(&views);

    cout<< views<<endl;
 
return 0;
}