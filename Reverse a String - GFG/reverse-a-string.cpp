//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

string reverseWord(string str){
    
  //Your code here
  int len=str.size();
   int low=0;
    int high=len-1;
    
    while(low<=high)
    {
        swap(str[low],str[high]);
        low++;
        high--;
    }
    string ans=str;
    return ans;
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends