class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int n = s.size();
        int m = p.size();
        vector<int> ans;
        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++) {
            mp[p[i]]++;
        }
        int i = 0;
        int j = 0;
        int k = p.length();
        int sz = mp.size();
        while (j < n)
        {
            if (mp.find(s[j]) != mp.end()) 
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                 {
                    sz--;
                }
            }
            if (j - i + 1 < k) 
            {
                j++;
            } 
            else if (j - i + 1 == k)
             {
                if (sz == 0)
                {
                    ans.push_back(i);
                }
                if (mp.find(s[i]) != mp.end()) // do calculation on i;
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1) 
                    {
                        sz++;
                    }
                        i++;
                        j++;
                }
                else if(mp.find(s[i])==mp.end()){
                    i++;j++;
                }
                    // }
                    // // else{
                    // i++;
                    // j++;
             }
            }

        return ans;
    }
};