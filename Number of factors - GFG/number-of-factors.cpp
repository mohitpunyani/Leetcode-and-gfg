//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int countFactors(int N)
    {
        //code here
      
        // METHOD 1  
        
        
        // int cnt=1;
        // for(int i=2;i<=N;i++)
        // {
        //     if(N%i==0)
        //     {
        //         cnt++;
        //     }
        // }
        // return cnt;
        
        
        // METHOD 2
        
        
    //   int cnt=2;
      
    //   if(N==1)
    //   {
    //       return 1;
    //   }
    //   for(int i=2;i<=sqrt(N);i++)
    //   {
    //       if(N%i==0)
    //       {
    //           cnt++;
               
    //           if(i*i!=N)
    //           {
    //               cnt++;
    //           }
    //       }
    //   }
    //   return cnt;
    
    // METHOD 3 -> MORE OPTIMIZATION
    
    
    int res=1;
    for(int i=2;i<=sqrt(N);i++)
    {
        
        int cnt=0;
        
        while(N%i==0)
        {
            cnt++;
            N=N/i;
        }
        
        res=res*(cnt+1);
        
    }
    
    if(N>=2){
        res=res*2;
    }
    return res;
        
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
        cout << ob.countFactors(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends