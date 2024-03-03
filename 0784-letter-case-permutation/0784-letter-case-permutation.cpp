class Solution {
public:
    
    
    // MY APPROACH  OR MY WAY TO SOLVE CODE
    
    vector<string>ans;
    
    void solve(string S,string op,int index)
    {
        if(index>=S.size()){
            ans.push_back(op);
            return ;
        }
        
        if(isalpha(S[index]))
        {
            // lower case
            
            op.push_back(tolower(S[index]));
            solve(S,op,index+1);
            op.pop_back();
            
            //  upper case
            op.push_back(toupper(S[index]));
            
            solve(S,op,index+1);
            op.pop_back();
        }
        else if(isdigit(S[index]))
        {
            op.push_back(S[index]);
            solve(S,op,index+1);
            op.pop_back();
        }
        return ;
        
    }
    vector<string> letterCasePermutation(string s) 
    {
        string op="";
        solve(s,op,0);
        return ans;
    
    }
};