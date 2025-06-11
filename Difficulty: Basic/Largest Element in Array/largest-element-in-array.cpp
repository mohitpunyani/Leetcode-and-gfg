class Solution {
  public:
      int mx=INT_MIN;
    int largest(vector<int> &arr)
    {
        int max=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]>max)
            max=arr[i];
            
        }
        return max;
    }
};
