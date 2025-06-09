class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        intervals.push_back({newInterval[0],newInterval[1]});
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
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
                ans.push_back({first,second});
                first=curr_first;
                second=curr_second;

            }

        }
        ans.push_back({first,second});
        return ans;
        
    }
};