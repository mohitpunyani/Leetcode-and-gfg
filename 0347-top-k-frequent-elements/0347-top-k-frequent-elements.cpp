class Solution {
public:
     priority_queue<pair<int,int>>pq;
    unordered_map<int,int>mp;
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;

        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty() && k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};