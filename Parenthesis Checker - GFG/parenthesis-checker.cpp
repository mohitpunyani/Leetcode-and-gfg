//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        
        // MY APPROACH 
        
    //     stack<char>st;
    //     for(int i=0;i<x.size();i++)
    //     {
    //         if(st.empty() && (x[i]==')' or x[i]==']' or x[i]=='}')){
    //             return false;
    //         }
    //         if(x[i]=='(' or x[i]=='[' or x[i]=='{'){
    //             st.push(x[i]);
    //         }
    // else if((st.top()=='(' && !st.empty() && x[i]==')') or (st.top()=='[' && !st.empty() && x[i]==']') or (st.top()=='{' && x[i]=='}'
    // && !st.empty())){
    //     st.pop();
    //     }
    // else{
    //     return false;
    // }
            
    //     }
    //     if(st.size()==0){
    //         return true;
    //     }
    //     return false;
    
    
    // ANOTHER APPROACH USING MAP
    unordered_map<char,int>mp={{'(',1},{')',-1},{'[',2},{']',-2},{'{',3},{'}',-3}};
    
    stack<char>st;
    
    for(int i=0;i<x.size();i++)
    {
        
      
         if(st.empty() && (x[i]==')' or x[i]==']' or x[i]=='}')){
                return false;
            }
        if(mp[x[i]]>0)
        {
                // we find a opening bracket
                
                st.push(x[i]);
        }
        else{
            if(mp[x[i]]+mp[st.top()]!=0){
                return false;
            }
            else{
                st.pop();
            }
        }
        
    }
    if(st.size()==0){
        return true;
    }
    return false;
}
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends