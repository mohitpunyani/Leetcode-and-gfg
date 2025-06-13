class Solution {
public:
    int romanToInt(string s) 
    {
        map<char,int>mp;
        mp.insert({{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}});
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=mp[s[i]];
            int y=mp[s[i+1]];
            if(x>=y)
            {
                ans=ans+x;
            }
            else{
                ans=ans+(y-x);
                i++;
            }

        }
        return ans;
    }
};