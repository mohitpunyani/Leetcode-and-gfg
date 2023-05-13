//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:



    void solve(int ind,string S,int n,string ans,vector<string>&res){
        if(ind==n){
            res.push_back(ans);
            return;
        }
        solve(ind+1,S,n,ans+' '+S[ind],res);
        solve(ind+1,S,n,ans+S[ind],res);
    }

    vector<string> permutation(string S)
    {
        // Code Here
        
        // jaise dry run kar raha vaise code likhade
      
        
         int n=S.size();
        string ans="";
        ans+=S[0];
        vector<string>res;
        solve(1,S,n,ans,res);
        return res;
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