class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k)
    {
        // write code here
        
        int i=0;
        int j=0;
        int n=arr.size();
        vector<int>ans;
        
        while(j<n && n-i>=k){
            if(arr[j]<0){
                ans.push_back(arr[j]);
                i++;
               if(i>j) j++;
            }
            else{
                if(j-i+1==k){
                    ans.push_back(0);
                    i++;
                    j++;
                }
                else{
                    j++;
                }
                
                
            }
        }
        return ans;
    }
};