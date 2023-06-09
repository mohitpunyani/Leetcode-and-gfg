class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size()==0){
            return 0;
        }
        unordered_map<char,int> mp;
        // this is a problem of fixed size sliding window
        // yaha par kabhi greater than condition toh aayegi nahi.
        
        int i=0;
        int j=0;
        int mx=INT_MIN;
        int size=s.length();
        while(j<size)
        {
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                    
                }
                j++;
        
             
            }

        }
        return mx;
        
    }
};