//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> nextsmallerelements(int *arr, int  n)
    {
        stack<pair<int,int >>s;
        
        s.push({arr[0],0});
        
        vector<int> ans(n,-1);

        for(int i = 1; i<n; i++){
        
            while(!s.empty()  && s.top().first> arr[i])
            {
                ans[s.top().second]=i;
                s.pop();
            }
            s.push({arr[i],i});
        }
        return ans;
    }

    vector<int> prevsmallerelements(int *arr, int n)
    {
        
      
        stack<pair<int,int>> st;
        
        vector<int> ans(n,-1);
        
        st.push({arr[n-1],n-1});
        
        for(int i= n-2; i >=0; i--){
    
            while(!st.empty() && st.top().first > arr[i])
            {
                ans[st.top().second]=i;
                st.pop();
            }

            st.push({arr[i],i});
        }
        return ans;
    }
    
     int  getMaxArea(int *arr, int n)
    {
        // Your code here
        
        vector<int > next(n); 
        next = nextsmallerelements(arr, n);
        
        vector<int> prev(n); 
        prev = prevsmallerelements(arr, n);
        
        int area = INT_MIN;
        
        for(int i = 0; i < n ; i++){
            
            int l = arr[i];
            
            if(next[i] == -1)
            {
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;
            
            int newarea = l * b;
            
            area = max(newarea, area);
        }
        
        return area;
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // Your code here
    
    
       // step 1 find answer for first row or find area for first row
       
       int area=getMaxArea(M[0],m);
       
       for(int i=1;i<n;i++){
           for(int j=0;j<m;j++)
           {
               // update row
               // by adding previous row's values
               
               if(M[i][j]!=0){
               M[i][j]=M[i][j]+M[i-1][j];
                   
               }
               else{
                   M[i][j]=0;
               }
           }
           // entire row is updated row
           
           area=max(area,getMaxArea(M[i],m));
       }
       return area;
       
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends