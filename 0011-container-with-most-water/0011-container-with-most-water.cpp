class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=(int)height.size();
        int ans=0;
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int h=min(height[left],height[right]);
            int b=right-left;
            int result=(h*b);
            ans=max(result,ans);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
            
        }
        return ans;
        
    }
};