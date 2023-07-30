//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool three(int number)
    {
        
        while(number!=0)
        {
            int rem=number%10;
            if(rem==3)
            {
                return true;
            }
            number=number/10;
        }
        return false;
    }
    int count(int n)
    {
        // // code here
        
        int ct=0;
        for(int i=3;i<=n;i++)
        {
            if(three(i))
            {
                ct++;
            }
          
        }
        return n-ct;
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
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends