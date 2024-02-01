#include<iostream>
#include<unordered_set>
#include<climits>
using namespace std;

string s = "thequickbrownfox";

string words[] = {"the","fox","quickbrown","quick","brown"};

int min_bars_helper(string s, string words[], int idx, unordered_set<string> &m){
    //base case
    if(s[idx]=='\0'){ //NULL value
        return 0;
    }

    //rec case
    int ans = INT_MAX;
    string current_string = ""; //current string we have formed is NULL

    for(int j  = idx; s[j] !=  '\0' ; j++){ //consedering all prefix and all subproblem
        current_string += s[j];

        //at every step we can check if this prefix is presen in set
        if(m.find(current_string) != m.end()){
            int remaining_ans = min_bars_helper(s,words,j+1,m);

            if(remaining_ans != -1){ //problem with the greedy approach
                ans =  min(ans, 1+remaining_ans);

            }
        }
    }
    if(ans == INT_MAX){
        return -1;
    }
    return ans; 
}

//Main logic
int min_bars(){
    unordered_set<string> m;

    for(string w:words){
        m.insert(w);
    }

    //recursive helper function
    int output = min_bars_helper(s,words,0,m);
    return output-1; //we do ans -1 because a pratition aslo created after the last stiring


}
  
int main(){

    cout<<min_bars();
 

 
return 0;
}