class Solution {
public:
    
    vector<string>ans;
    
    void solve(string S,string op,int i){
        if(i==S.size()){
            ans.push_back(op);
            return ;
        }
        if(isalpha(S[i]))
        {
            string op1=op;
            op1.push_back(tolower(S[i]));
            solve(S,op1,i+1);
            
            string op2=op;
            op2.push_back(toupper(S[i]));
            solve(S,op2,i+1);
            return ;
        }
        else{
            // when we have digit
            
            string op3=op;
            op3.push_back(S[i]);
            solve(S,op3,i+1);
            return ;
        }
    }
    vector<string> letterCasePermutation(string s) 
    {
        
        string op="";
        solve(s,op,0);
        return ans;
    }
};