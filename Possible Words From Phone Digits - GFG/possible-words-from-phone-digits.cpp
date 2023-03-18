//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //   unordered_map<int,string> mp;
    //     mp.insert({1,""});
    //     mp.insert({2,"abc"});
    //     mp.insert({3,"def"});
    //     mp.insert({4,"ghi"});
    //     mp.insert({5,"jkl"});
    //     mp.insert({6,"mno"});
    //     mp.insert({7,"pqrs"});
    //     mp.insert({8,"tuv"});
    //     mp.insert({9,"wxyz"});
        
    void solve(int a[],string &op, int index, unordered_map<int,string> &mp,vector<string>
    &ans,int N)
    {
        if(index>=N){
            ans.push_back(op);
            return ;
        }
        int digit=a[index];
        string value=mp[digit];
        for(int i=0;i<value.size();i++){
            op.push_back(value[i]);
            solve(a,op,index+1,mp,ans,N);
            op.pop_back();
        }
        return ;
        
        
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        // solve using ip op method
        
        //Your code here
        unordered_map<int,string> mp;
        mp.insert({1,""});
        mp.insert({2,"abc"});
        mp.insert({3,"def"});
        mp.insert({4,"ghi"});
        mp.insert({5,"jkl"});
        mp.insert({6,"mno"});
        mp.insert({7,"pqrs"});
        mp.insert({8,"tuv"});
        mp.insert({9,"wxyz"});
    
    vector<string> ans;
    string op="";
    int index=0;
    solve(a,op,index,mp,ans,N);
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends