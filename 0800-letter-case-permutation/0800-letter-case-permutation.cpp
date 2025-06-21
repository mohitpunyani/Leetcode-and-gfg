class Solution {
    
    private:
    
    void solve(string ip,string op,vector<string> &ans){
        if(ip.size()==0)
        {
            ans.push_back(op);
            return ;
        }
        if(isalpha(ip[0]))
        {
            string op1=op;
            string op2=op;
            op1.push_back(tolower (ip[0]));
            op2.push_back(toupper (ip[0]));
            ip.erase(ip.begin()+0);
            solve(ip,op1,ans);
            solve(ip,op2,ans);
            
        }
        // agar alphabet nahi hai toh mere paas ek hi choice hai.
        
        else{
            
            
            string op3=op;
            op3.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            solve(ip,op3,ans);
            
        }
    }
public:
    vector<string> letterCasePermutation(string s) 
    {
        vector<string> ans;
        string op="";
        solve(s,op,ans);
        return ans;
        
        
    }
};