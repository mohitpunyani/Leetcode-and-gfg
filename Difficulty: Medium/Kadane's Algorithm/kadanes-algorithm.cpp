class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        
        int n=arr.size();
        int curr_sum=0;
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            curr_sum=max(curr_sum+arr[i],arr[i]);
            mx=max(mx,curr_sum);
            
        }
        return mx;
    }
};