class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int>mxheap;
        for(int i=0;i<nums.size();i++)
        {
            mxheap.push(nums[i]);
        }
        while(!mxheap.empty() && k>1){
            mxheap.pop();
            k--;
        }
        return mxheap.top();
        
    }
};