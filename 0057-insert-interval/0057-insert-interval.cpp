class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> ans;
        vector<int>temp;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int first=intervals[0][0];
        int second=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(second>=intervals[i][0]){
                second=max(second,intervals[i][1]);
            }
            else{
                temp.push_back(first);
                temp.push_back(second);
                ans.push_back(temp);
                temp.clear();
                second=intervals[i][1];
                first=intervals[i][0];
            }
            
        }
        temp.push_back(first);
        temp.push_back(second);
        ans.push_back(temp);
        return ans;
        
    }
};