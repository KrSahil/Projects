#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
1. Generate all substring
2. Generate their hash
3. Hash the 'Hash' values to club all anagrams in single bucket, to get their frequecy count
4. From freq count, we can easily count the pairs
*/

vector<int> getHashValue(string s, int i, int j){

    //frequency vector of 26 elements all initialized to 0
    vector<int> freq(26,0);

    //iterate oveer the original string from i to j to fill this vector
    for(int k=i; k<=j; k++){
        char ch = s[k];
        freq[ch-'a']++;
    }
    return freq;  

}

int anagrams_substring(string s){
    
    //we have map and not unordered map becuase, the key is  a complex object 
    //and map by default can handle key of the type of vector<int>
    //but for hashmap we need to give ur own hash function for it
    map<vector<int> , int> m; //the key is vector and int is frequency

    //generating all the substring
    for (int i = 0; i<s.length(); i++){      //0(n^2)
        for (int j = i; j<s.length(); j++){
            //Substring s[i....j]

            //generate hash value for each substring
            vector<int> h = getHashValue(s,i,j);    //o(n)
            //put it inside the map
            m[h]++; //the no of time same vector is generating, we are increasing it's frequency in a hashmap
        }
    }
    //by now we know , what vectors are generated and how many times they are genarated
    
    //pairs
    int ans = 0;
    for(auto p:m){      //O(N^2)

        int freq = p.second;
        if(freq >= 2){
            ans += (freq)*(freq-1)/2;
        }
    }
    return ans;

}

int main(){
        string s;
        cin>>s;

        cout<<anagrams_substring(s);

    return 0;
}

//O(N^3)