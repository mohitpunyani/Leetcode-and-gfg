//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here
        int count_zero=0;
        int count_first=0;
        int count_second=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0){
                count_zero++;
            }
            else if(a[i]==1){
                count_first++;
            }
            else{
                count_second++;
            }
            
        }
        for(int i=0;i<n;i++){
            
            if(count_zero!=0){
                a[i]=0;
                count_zero--;
            }
            else if(count_first!=0){
                a[i]=1;
                count_first--;
                
            }
            else{
                a[i]=2;
                count_second--;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends