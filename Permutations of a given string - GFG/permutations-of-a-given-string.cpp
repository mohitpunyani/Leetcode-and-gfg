//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
        public:
    //Complete this function
    
    vector<string> ans;
    
    void solve(string &S,int index)
    {
        if(index==S.size()){
            ans.push_back(S);
            return ;
        }
        for(int j=index;j<S.size();j++)
        {
            swap(S[index],S[j]);
            solve(S,index+1);
            
            // backtrack
            
            swap(S[index],S[j]);
            
        }
        return ;
        
    }
    vector<string> find_permutation(string S)
    {
        //Your code here
        
        // ek permutation nikal ne ka baad sara game swap ka hai
        
        // ek ko fix man kar swap kar
        

        solve(S,0);
        sort(ans.begin(),ans.end());
        // ans.resize(unique(ans.begin(),ans.end()));
                ans.erase(unique(ans.begin(),ans.end()),ans.end());

        return ans;
        
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends