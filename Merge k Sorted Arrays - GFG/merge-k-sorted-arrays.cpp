//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        
        // k tells that question is of heap
        
        // here we have to use min heap
        
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>minheap;
        
        int row=arr.size();
        int col=arr[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                minheap.push(arr[i][j]);
            }
        }
        while(!minheap.empty()){
            ans.push_back(minheap.top());
            minheap.pop();
        }
        return ans;
        
        
        
        
        

    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends