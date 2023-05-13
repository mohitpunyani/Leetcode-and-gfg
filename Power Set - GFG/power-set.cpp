//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<string>ans;
	

	void Helper(string &s,int idx,vector<string> &ans,string &out){
        //BASE CASE
        if(idx>=s.length()){
            if(out.length()>0){
                ans.push_back(out);
            }
            return;
        }
        // include
        out.push_back(s[idx]);
        Helper(s,idx+1,ans,out);
        //exclude
        out.pop_back();
        Helper(s,idx+1,ans,out);
    }
		vector<string> AllPossibleStrings(string s)
		{
		    // Code here

		        vector<string>ans;
		    string out = "";
		    int idx = 0;
		    Helper(s,idx,ans,out);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends