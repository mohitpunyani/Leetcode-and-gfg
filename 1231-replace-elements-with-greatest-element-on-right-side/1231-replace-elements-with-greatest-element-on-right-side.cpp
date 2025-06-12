class Solution {
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        int n=arr.size();
        if(n==1){
            arr[0]=-1;
            return arr;
        }
        int mx=arr[n-1];
        arr[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            int temp=arr[i];
            arr[i]=mx;
            mx=max(mx,temp);
        }
        return arr;
    }
};