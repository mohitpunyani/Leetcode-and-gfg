class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int>dq;
        int i=0;
        int j=0;
        int n=nums.size();
        int mx=INT_MIN;
        vector<int>ans;
        while(j<n)
        {
            
            while(dq.size()!=0 && nums[j]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else{
                ans.push_back(dq.front());
                if(nums[i]==dq.front()){
                dq.pop_front();
                }
                i++;
                j++;
            }

        }
        return ans;
        
    }
};