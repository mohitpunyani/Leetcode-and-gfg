//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    // code here
    
    stack<char>st;
    
    for(int i=0;i<s.size();i++)
    {
        if(st.empty() && (s[i]==')' or s[i]==']'  or s[i]=='}'))
        {
           return false;
        }
    if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
        st.push(s[i]);
    }
    else if((st.top()=='(' && s[i]==')') or  (st.top()=='[' && s[i]==']') or (st.top()=='{' && s[i]=='}'))
    {
        st.pop();
    }
    else{
        return false;
    }
    }
    if(st.size()==0){
        return true;
    }
    else{
        return false;
    }
}