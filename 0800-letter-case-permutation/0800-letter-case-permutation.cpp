class Solution {
public:
vector<string>ans;
void solve(string s,string temp,int idx )
{
    if(idx>=s.size()){
        ans.push_back(temp);
        return ;
    }
    if(isdigit(s[idx]))
    {
        // we have only one choice
        solve(s,temp+s[idx],idx+1);
        return ;

    }
    if(isalpha(s[idx]))
    {
        char a=tolower(s[idx]);
        solve(s,temp+a,idx+1);
        char b=toupper(s[idx]);
        solve(s,temp+b,idx+1);

    }
    return ;

}
    vector<string> letterCasePermutation(string s) 
    {
        string temp="";
        solve(s,temp,0);
        return ans;
    }
};