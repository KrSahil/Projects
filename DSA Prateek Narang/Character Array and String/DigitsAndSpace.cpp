#include<iostream>
using namespace std;

//given, a sentence count the number of alphabets,digits and space

  
int main(){

    /* two ways
    Store and the count 
    Read one by one then count - we use this

    */

   char ch;

   ch = cin.get();  // 1 st character we read from here

   // we need to give three variales for alphabet string and number

   int alpha=0;
   int space=0;
   int digit=0;

   while (ch!='\n'){

       if (ch>='0' and ch<='9' ) {// we are able to use this code because every
                                // digits has a ASCII value. So, we are able to distinguis the numbers from alphabets
            digit++;
         }
        else if ((ch>= 'a' and ch<='z') or (ch>= 'A' and ch<= 'Z')){
            alpha++;
        }
        else if (ch==' ' or ch =='\t'){  //'\t' tab is also kind of space 
            space++;
        }


       ch=cin.get();  // and remaining character we read from here

   }
   cout<<"Total digits"<<digit<<endl;
   cout<<"Total Alphabets"<<alpha<<endl; 
   cout<<"Total space"<<space<<endl; 
    
    
    return 0;
}