//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends