//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue
void solve(queue<int>&q,int index,int k)
{
    if(index>=k)
    {
        return ;
    }
    int value=q.front();
    q.pop();
    solve(q,index+1,k);
    q.push(value);
    return ;
}
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here
    solve(q,0,k);
    
    int len=q.size()-k;
    for(int i=1;i<=len;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
    
    
    
}