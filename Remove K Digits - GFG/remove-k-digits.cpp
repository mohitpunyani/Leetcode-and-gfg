//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) 
    {
        
        if(K>=S.size()){
            return "0";
        }
        stack<char>st;
        
        st.push(S[0]);
        
        string ans="";
        
        if(st.top()=='0'){
            st.pop();
        }
        for(int i=1;i<S.size();i++){
            
            while(!st.empty() && K!=0  && st.top()>S[i])
            {
                
                K--;
                
                st.pop();
            }
            st.push(S[i]);
            

            // removing leading zeroes
            if(st.size()==1 && S[i]=='0'){
                st.pop();
            } 
            
        }
        
        while(K!=0 && !st.empty())
        {
            K--;
            st.pop();
        }
    
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        if(ans.size()==0){
            return "0";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends