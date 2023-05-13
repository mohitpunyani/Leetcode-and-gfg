//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string>ans;
    void solve(string &S,int index){
        
        if(index>=S.size()){
            ans.push_back(S);
            return ;
        }
        for(int j=index;j<S.size();j++){
            swap(S[j],S[index]);
            solve(S,index+1);
            swap(S[j],S[index]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        solve(S,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends