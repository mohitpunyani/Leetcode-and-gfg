//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Your code goes hereclass Solution{
	
class Solution{
	public:
	void sortedMerge(int a[], int b[], int res[],int n, int m)
	{
	   // Your code goes here
	   sort(a,a+n);
	   sort(b,b+m);
	   
	   int i=0;
	   int j=0;
	   
	   int k=0;
	   while(i<n && j<m)
	   {
	       
	       if(a[i]<b[j])
	       {
	           res[k]=a[i];
	           i++;
	           k++;
	       }
	       else if(a[i]>b[j])
	       {
	           res[k]=b[j];
	           j++;
	           k++;
	           
	       }
	       else{
	           res[k]=a[i];
	           //i++;
	           j++;
	           k++;
	       }
	   }
	   while(i<n)
	   {
	       // yah toh i bach gaya 
	       
	       res[k]=a[i];
	       i++;
	       k++;
	   }
	   while(j<m)
	   {
	       
	       //yaha toh j bach gaya
	       
	       res[k]=b[j];
	       j++;
	       k++;
	   }
	}
};
	  


//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }

	    for(int i = 0;i<m;i++){
	        cin >> b[i];
	    }
	    
	    int res[n+m];

      
        Solution ob;
        ob.sortedMerge(a,b,res,n,m);

        for(int i = 0;i<n+m;i++){
	        cout << res[i] << " ";
	    }
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends