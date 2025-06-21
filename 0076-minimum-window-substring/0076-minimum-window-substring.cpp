class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n=s.length();
        int m = t.length();
        int len =n;
        string ans="";
        if(m>n){
            return ans;
        }
        unordered_map<char, int> mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int cnt =mp.size();

        int i=0, j=0;
        while(j<n)
        {
            if(mp.find(s[j])==mp.end())
            {
                // j++;
            }
            else if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    cnt--;
                }
                // j++;
            }
            if(cnt==0)
            {
                while(cnt==0)
                {
                    if(mp.find(s[i])!=mp.end() && mp[s[i]]<0){
                        mp[s[i]]++;
                        i++;
                    }
                    else if(mp.find(s[i])!=mp.end() && mp[s[i]]==0){
                        break;
                    }
                    else if(mp.find(s[i])==mp.end()) 
                        i++;
                }
                if(len>=j-i+1){
                    ans =s.substr(i, j-i+1);
                    // substr(pos,size);
                    len = j-i+1;
                }
            } 
            j++;
        }
        return ans;
    
    }
};