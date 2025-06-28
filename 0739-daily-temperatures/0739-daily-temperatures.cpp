class Solution {
public:
// ngl pattern (just observation)
    stack<pair<int,int>>st;
    void solve(vector<int>&temperatures,vector<int>&ans)
    {
        for(int i=temperatures.size()-1;i>=0;i--)
        {

            while(!st.empty() && temperatures[i]>=st.top().first)
            {
                st.pop();
            }

            ans[i] = st.empty() ? 0: st.top().second-i;
            st.push({temperatures[i],i});

        }
        return ;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n=temperatures.size();
        vector<int>ans(n);
        solve(temperatures,ans);
        return ans;
        
    }
};