//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        
        // IMPORTANT APPROACH (IMP CONCEPT);
        
       int n=nums.size();
       
       int res1=0;
       
       for(int i=0;i<n;i++)
       {
           res1=res1^nums[i];
       }
       int ans_1=0;
       int ans_2=0;
       
       int right_most_set_bit=res1 & (~(res1-1));
       
       for(int i=0;i<n;i++)
       {
           if((nums[i]&right_most_set_bit)!=0)
           {
               ans_1=ans_1^nums[i];
           }
           else{
               ans_2=ans_2^nums[i];
           }
           
       }
       
       vector<int>ans;
       
       if(ans_1>ans_2)
       {
           ans.push_back(ans_2);
           ans.push_back(ans_1);
       }
       else{
           ans.push_back(ans_1);
           ans.push_back(ans_2);
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends