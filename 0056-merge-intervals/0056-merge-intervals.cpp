class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int first=intervals[0][0];
        int second=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            int curr_first=intervals[i][0];
            int curr_second=intervals[i][1];
            if(second>=curr_first){
                second=max(second,curr_second);
            }
            else{
                temp.push_back(first);
                temp.push_back(second);
                ans.push_back(temp);
                temp.clear();
                first=curr_first;
                second=curr_second;

            }

        }
        temp.clear();
        temp.push_back(first);
        temp.push_back(second);
        ans.push_back(temp);
        return ans;
        
    }
};