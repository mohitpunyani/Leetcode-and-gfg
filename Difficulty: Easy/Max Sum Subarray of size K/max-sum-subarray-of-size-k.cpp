class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k)
    {
        // code here
        
        int i=0;
        int j=0;
        int n=arr.size();
        int s=0;
        int mx=0;
        while(j<n){
            s=s+arr[j];
            if(j-i+1<k){
                j++;
            }
            else{
                mx=max(mx,s);
                s=s-arr[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};