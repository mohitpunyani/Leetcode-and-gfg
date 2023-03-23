class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // sort on the basis of end
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        int first=intervals[0][0];
        int second=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(second>=intervals[i][0])
            {
                second=max(second,intervals[i][1]);
                
            }
            else{
                
                temp.push_back(first);
                temp.push_back(second);
                ans.push_back(temp);
                first=intervals[i][0];
                second=intervals[i][1];
                temp.clear();
                
            }
            
        }
        temp.push_back(first);
        temp.push_back(second);
        ans.push_back(temp);
        return ans;
        
    }
};