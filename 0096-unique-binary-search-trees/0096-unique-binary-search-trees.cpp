class Solution
{
    public:
    int recursive(int n)
    {
        if(n==0 or n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int ans=0;
        
        // observe carefully
        for(int i=1;i<=n;i++)
        {
            
            ans=ans+recursive(i-1)*recursive(n-i); // catalan formula
        }
        return ans;
        
    }
        int numTrees(int n)
        {
            return recursive(n);
            
        }
};