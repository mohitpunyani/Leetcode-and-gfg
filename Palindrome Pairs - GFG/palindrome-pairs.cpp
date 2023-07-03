//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    // Function to check if a palindrome pair exists
    
    
    bool ispalindrome(string str)
    {
        
        int low=0;
        int high=str.size()-1;
        if(str.size()==1)
        {
            return true;
        }
        while(low<high){
            if(str[low]!=str[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    
    bool palindromepair(int N, string arr[]) 
    {
        // code here
        
        // EASY QUESTION (EASY APPROACH DIRECT COMES IN MY MIND)
        
        
        // for(int i=0;i<N-1;i++)
        // {
        //     for(int j=i+1;j<N;j++)
        //     {
        //         string str1=arr[i]+arr[j];
                
        //         string str2=arr[j]+arr[i];
        //         if(ispalindrome(str1) or ispalindrome(str2))
        //         {
        //             return true;
        //         }
                
        //     }
        // }
        // return false;
        
        // optimized approach using map
        
        // AYSUHI SHARMA APPROACH 
        
        unordered_map<string,int>mp;
        for(int i=0;i<N;i++)
        {
            auto s=arr[i];
            reverse(s.begin(),s.end());
            mp[s]=i;
            
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<arr[i].size();j++)
            {
                // also taken empt
                
                string s1=arr[i].substr(0,j);
                string s2=arr[i].substr(j);
                
                // agar prefix palindrome hua and suffix map ke aandar hua that means we find a pair
                
                if(mp.find(s2)!=mp.end()  && ispalindrome(s1) && mp[s2]!=i) 
                {
                    return true;
                    
                }
                if(mp.find(s1)!=mp.end() && ispalindrome(s2) && mp[s1]!=i){
                    return true;
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends