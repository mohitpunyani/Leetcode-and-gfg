//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     
     int j=0; // for x traversal
     
     int ans=-1;
     
     for(int i=0;i<s.size();i++)
     {
         if(s[i]==x[0])
         {
             ans=i;
             int j=0;
             while(j<x.size() && i<s.size())
             {
                 
                 if(s[i]==x[j])
                 {
                     i++;
                    //  if(j==x.size()-1){
                    //      return ans;
                    //  }
                     j++;
                     if(j==x.size())
                     {
                         return ans;
                     }
                 }
                 else{
                     i=ans;
                     break;
                 }
             }
             
         }
         else{
             continue;
         }
         
     }
     return -1;
     
}