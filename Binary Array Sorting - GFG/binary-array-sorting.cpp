//{ Driver Code Starts
// A Sample C++ program for beginners with Competitive Programming

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int A[], int N)
    {
       //Your code here
       
       /**************
        * No need to print the array
        * ************/
        int n=N;
        int count_zero=0;
        int count_one=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]==0){
                count_zero++;
            }
            else{
                count_one++;
            }
        }
        for(int i=0;i<n;i++){
            if(count_zero!=0)
            {
                A[i]=0;
                count_zero--;
            }
            else{
                A[i]=1;
                count_one--;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    Solution obj;
	    obj.binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}




// } Driver Code Ends