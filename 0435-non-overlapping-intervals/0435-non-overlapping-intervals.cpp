class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
     {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int first=intervals[0][0];
        int second=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int curr_first=intervals[i][0];
            int curr_second=intervals[i][1];
            if(second>curr_first){
                second=min(second,curr_second);
                count++;
            }
            else{
                first=curr_first;
                second=curr_second;
            }
        }
        
    return count;
    }
};