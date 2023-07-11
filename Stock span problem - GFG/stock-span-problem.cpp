//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       
       // ngl
       stack<pair<int,int>> st;
       vector<int>ans(n,-1);
       st.push({0,price[0]});
       for(int i=1;i<n;i++)
       {
           
           while(!st.empty() && st.top().second<=price[i])
           {
               st.pop();
           }
           if(!st.empty() && st.top().second>price[i])
           {
               ans[i]=st.top().first;
           }
           st.push({i,price[i]});
           
       }
       for(int i=0;i<n;i++){
           ans[i]=i-ans[i];
       }
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends