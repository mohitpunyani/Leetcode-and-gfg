//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second<b.second; // if it is true than do nothing move forward
        
        // else swap done take place 
        
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        
        // think greedy and apply on real life
        
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        
        // observation as we know
        
        // start[i]<end[i] 
        
        sort(v.begin(),v.end(),comp); // sort on the basis of ending time 
        
        int count=1;
        
        int prev=v[0].second;
        
        for(int i=1;i<n;i++)
        {
            int curr=v[i].first;
            
            if(curr>prev)
            {
                // now it is possible 
                count++;
                prev=v[i].second;
            }
            else{
                continue;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends