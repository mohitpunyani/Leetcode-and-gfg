//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

vector<string> ans;

void solve(string &ip,string op,int index){
    if(index>=ip.size()-1){
        op.push_back(ip[index]);
        ans.push_back(op);
        return ;
    }
    op.push_back(ip[index]);
    op.push_back(' ');
    // inclusion  (character with space)
    solve(ip,op,index+1);
    // exclusion (character without space)
    op.pop_back();
    solve(ip,op,index+1);
    return ;
}
    vector<string> permutation(string S)
    {
        // Code Here
        int n=S.size();
        string op="";
        solve(S,op,0);
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