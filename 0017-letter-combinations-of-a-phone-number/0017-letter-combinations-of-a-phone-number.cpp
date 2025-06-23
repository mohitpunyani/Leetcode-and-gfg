class Solution {
public:
    vector<string>ans;
    void solve(string digits,unordered_map<char,string>&mp,string temp,int idx)
    {
        if(idx>=digits.size())
        {
            ans.push_back(temp);
            return ;
        }
        string value=mp[digits[idx]];
        for(int i=0;i<value.size();i++)
        {
            temp.push_back(value[i]);
            solve(digits,mp,temp,idx+1);
            temp.pop_back(); // backtrack
        }
        return ;

    }
    vector<string> letterCombinations(string digits) 
    {
        int n=digits.size();
        if(digits.size()==0){
            return {};
        }
unordered_map<char, string> mp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"}, {'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
        
        string temp="";
        solve(digits,mp,temp,0);
        return ans;
    }
};