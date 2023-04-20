//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements\
        
        vector<int> res;
        
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            // ignore duplicates 
            while(arr1[i]==arr1[i+1])
            {
                i++;
            }
            // ignore duplicates
            while(arr2[j]==arr2[j+1]){
                j++;
            }

            if(arr1[i]<arr2[j]){
                res.push_back(arr1[i]);
                i++;
            }
            else if(arr1[i]>arr2[j]){
                res.push_back(arr2[j]);
                j++;
            }
            else{
                res.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        // suppose agar koi ek array pura traverse hoga than toh dusare array ke jabhi elements result array me dhal do
        
        while(i<n)
        {
            while(arr1[i]==arr1[i+1]){
                i++;
            }
        res.push_back(arr1[i]);
        i++;
        }
        
        while(j<m)
        {
            while(arr2[j]==arr2[j+1]){
                j++;
            }
        res.push_back(arr2[j]);
        j++;
        }        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends