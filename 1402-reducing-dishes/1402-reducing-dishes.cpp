class Solution {
    private:

    int recursive(vector<int> &satisfaction,int index,int time){
        if(index>=satisfaction.size()){
            return 0;
        }
        int include=satisfaction[index]*(time+1)+recursive(satisfaction,index+1,time+1);
        int exclude=0+recursive(satisfaction,index+1,time);
        int ans=max(include,exclude);
        return ans;
    }

    int topdowndp(vector<int> &satisfaction,int index,int time,vector<vector<int> > &dp){
        if(index>=satisfaction.size()){
            return 0;
        }
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        int include=satisfaction[index]*(time+1)+topdowndp(satisfaction,index+1,time+1,dp);
        int exclude=0+topdowndp(satisfaction,index+1,time,dp);
        int ans=max(include,exclude);
        dp[index][time]=ans;
        return dp[index][time]; 
    }
    int bottomupdp(vector<int> &satisfaction){
        
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int include=satisfaction[index]*(time+1)+dp[index+1][time+1];
                int exclude=0+dp[index+1][time];
                dp[index][time]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    // solve using one d arrays
    int bottomupdp2(vector<int> &satisfaction){

        int n=satisfaction.size();

        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--)
            {
                int include=satisfaction[index]*(time+1)+next[time+1];
                int exclude=0+next[time];
                curr[time]=max(include,exclude);
            }
            next=curr;
        }
        return next[0];

    }
    // best space optimization or greedy approach

    int optimization(vector<int> &satisfaction){
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int total=0;
        int start=n-1;
        for(int i=n-1;i>=0;i--){
            total=total+satisfaction[i];
            if(total<0){
                break;
            }
            start--;

        }
        start++;
        total=0;
        int time=1;
        // this is our starting point
        for(int i=start;i<n;i++){
            total+=time*satisfaction[i];
            time++;
        }
        return total;

    }
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        // based on 0-1 knapsack
        
        // recursive
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // return recursive(satisfaction,0,0); 

        // topdowndp

        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return topdowndp(satisfaction,0,0,dp);

        // bottomupdp

        // return bottomupdp(satisfaction);

        // return bottomupdp2(satisfaction);

        return optimization(satisfaction);
    }
};