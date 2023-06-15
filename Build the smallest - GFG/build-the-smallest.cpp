//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int K)
{
    //code here.
            if(K>=num.size()){
            return "0";
        }
        stack<char>st;
        
        st.push(num[0]);
        
        string ans="";
        
        
        // if starting digit is zero 
        
        if(st.top()=='0')
        {
            st.pop();
        }
        for(int i=1;i<num.size();i++){
            
            while(!st.empty() && K!=0  && st.top()>num[i])
            {
                
                K--;
                
                st.pop();
            }
            st.push(num[i]);
            

            // removing leading zeroes
            if(st.size()==1 && num[i]=='0'){
                st.pop();
            } 
            
        }
        
        while(K!=0 && !st.empty())
        {
            K--;
            st.pop();
        }
        
        if(st.size()==0){
            return "0";
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
}