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
    
    string manchester_algorithm(string s,int n)
    {
        
            
    
    
     n = s.size();
        int start = 0, end = 0, mx = INT_MIN;
        
        if(n<=1) return s;
        
        // for both even and odd length
        
        // SPECIALLY FOR ODD LENGTH
        
        // AND ALSO SPECIALLY FOR PALINDROMIC EVEN LENGTH SUBSTRING IN A GIVEN ODD LENGTH STRING 
        for(int i=0; i<n-1; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l]==s[r]){
                l--; r++;
            }
            int length = r-l-1;
            if(length > mx){
                mx = length;
                start = l+1;
                end = r-1;
            }
        }
          // for both even and odd length 
        
        
        // SPECIALLY FOR EVEN LENGTH
        
        // AND ALSO SPECIALLY FOR PALINDROMIC ODD LENGTH SUBSTRING IN A GIVEN EVEN LENGTH STRING 
        
        for(int i=0; i<n-1; i++){
            int l = i, r = i+1;
            while(l >= 0 && r < n && s[l]==s[r]){
                l--; r++;
            }
            int length = r-l-1;
            if(length > mx){
                mx = length;
                start = l+1;
                end = r-1;
            }
        }
        
        return s.substr(start, mx);
    }
    string longestPalindrome(string S)
    {
        // code here 
        
        // int n=S.size();
        
        // int max_length=0;
        
        // int i_max=0;
        
        // int j_max=0;
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         string temp=S.substr(i,j-i+1);
                
        //         // j-i+1 is the substring length
                
        //         if(is_palindrome(temp))
        //         {
                    
        //             if(j-i+1>max_length)
        //             {
        //                 max_length=j-i+1;
        //                 i_max=i;
        //                 j_max=j;
        //             }
        //         }
                
        //     }
            
        // }
        // return S.substr(i_max,j_max-i_max+1);
        
        int n=S.size();
        return manchester_algorithm(S,n);
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