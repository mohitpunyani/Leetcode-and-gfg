class Solution {
public:
    bool isprime(int a)
    {
        if(a<2){
            return false;
        }
        for(int i=2;i<=sqrt(a);i++)
        {
            if(a%i==0)
            {
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums)
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto &[_,a]:mp)
        {
            if(isprime(a))
            {
                return true;
                
            }
            
        }
        return false;
    }
};