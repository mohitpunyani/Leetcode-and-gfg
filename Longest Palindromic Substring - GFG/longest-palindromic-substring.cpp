//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
 bool is_palindrome(string S)
    {
        int n=S.size();
        int low=0;
        int high=n-1;
        while(low<high)
        {
            if(S[low]!=S[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    string longestPalindrome(string S)
    {
        // code here 
        
        int n=S.size();
        
        int max_length=0;
        
        int i_max=0;
        
        int j_max=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                string temp=S.substr(i,j-i+1);
                
                // j-i+1 is the substring length
                
                if(is_palindrome(temp))
                {
                    
                    if(j-i+1>max_length)
                    {
                        max_length=j-i+1;
                        i_max=i;
                        j_max=j;
                    }
                }
                
            }
            
        }
        return S.substr(i_max,j_max-i_max+1);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends