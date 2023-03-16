class Solution {
public:
    string intToRoman(int num) 
    {
        
        int n=num;
        map<int,string> mp;
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
        
        string result="";
        while(n!=0)
        {
            for(auto it=mp.rbegin();it!=mp.rend();it++)
            {
                // we do use this loop from rbegin to rend because in roman 
                // we will ascending order
                
                int value=it->first;
                if(n>=value)
                {
                    result=result+it->second;
                    n=n-value;
                    break;
                }
            }
        }
        return result;
    
    }
};