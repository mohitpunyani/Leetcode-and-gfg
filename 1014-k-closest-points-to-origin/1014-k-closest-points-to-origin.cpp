class Solution {
public:
    typedef pair<int,pair<int,int>> pi;

    priority_queue<pi,vector<pi>,greater<pi>> pq;
    // priority_queue<int,vector<int>,greater<int>> mnheap;

    vector<vector<int>>ans;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        for(int i=0;i<points.size();i++){
            int x_val=points[i][0];
            int y_val=points[i][1];

            x_val=x_val*x_val;
            y_val=y_val*y_val;
            
            int sum=x_val+y_val;
            int distance_from_origin=sum;
            pq.push({distance_from_origin,{points[i][0],points[i][1]}});
            
        }
        while(!pq.empty() && k>0)
        {
            pair<int,int>p=pq.top().second;
            vector<int>temp;
            temp.push_back(p.first);
            temp.push_back(p.second);
            ans.push_back(temp);
            pq.pop();
            k--;
        }
        return ans;
    }
};