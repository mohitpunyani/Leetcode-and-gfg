//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

vector<string>ans;

void solve(string S,string op,int i)
{
    if(i==S.size())
    {
        ans.push_back(op);
        return ;
        
    }
    solve(S,op+' '+S[i],i+1);
    solve(S,op+S[i],i+1);
    return ;
    
}

    vector<string> permutation(string S)
    {
        // Code Here
        
        // jaise dry run kar raha vaise code likhade
        string op="";
        op.push_back(S[0]);
        solve(S,op,1);
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends