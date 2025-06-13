class Solution {
public:
    string intToRoman(int num) 
    {
        string ans="";
        map<int,string>mp;
        mp.insert({1,"I"});
        mp.insert({4,"IV"});
        mp.insert({5,"V"});
        mp.insert({9,"IX"});
        mp.insert({10,"X"});
        mp.insert({40,"XL"});
        mp.insert({50,"L"});
        mp.insert({90,"XC"});   
        mp.insert({100,"C"});
        mp.insert({400,"CD"});
        mp.insert({500,"D"});
        mp.insert({900,"CM"});
        mp.insert({1000,"M"});
        while(num>0)
        {
            for(auto it=mp.rbegin();it!=mp.rend();it++)
            {
                if(num>=it->first)
                {
                    num=num-it->first;
                    ans=ans+it->second;
                    break;
                }
                else{
                    continue;
                }

            }
        }
        return ans;
    }
};