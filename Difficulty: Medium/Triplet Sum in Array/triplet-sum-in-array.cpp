class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target)
    {
        // Your Code Here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<=arr.size()-3;i++)
        {
            int start=i+1;
            int end=arr.size()-1;
            while(start<end)
            {
                int tg=target-arr[i];
                if(arr[start]+arr[end]==tg)
                {
                    return true;
                }
                else if(arr[start]+arr[end]>tg)
                {
                    end--;
                }
                else{
                    start++;
                }
                
            }
        }
        return false;
        
    }
};