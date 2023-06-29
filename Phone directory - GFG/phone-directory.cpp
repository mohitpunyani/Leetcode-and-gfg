//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode
{
    public:
    
    char data;
    
    TrieNode * children[26];  // array of characters
    
    bool isTerminal;
    
    TrieNode(char ch){
        
        data=ch;
        
        for(int i=0;i<26;i++){
            
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
    
    public:
    
    TrieNode*root;
    
    Trie(){
        root=new TrieNode('\0');
    }
    void insertutil(TrieNode*root,string str)
    {
        if(str.size()==0){
            root->isTerminal=true;
            return ;
        }
        
        TrieNode*child;
        
        int index=str[0]-'a';
        
        if(root->children[index]!=NULL)
        {
            // aage badh jao
            
            child=root->children[index];
            
        }
        else{
            child=new TrieNode(str[0]);
            root->children[index]=child;
            
        }
        
        insertutil(child,str.substr(1));
        return ;
    }
    void insertword(string str){
        insertutil(root,str);
        return ;
    }
    
    void print_suggestions(TrieNode*curr,vector<string>&temp,string prefix)
    {
        if(curr->isTerminal==true)
        {
            // you reach the end character
            
            temp.push_back(prefix);
            
            // return ;
        }
        for(char ch='a';ch<='z';ch++)
        {
            TrieNode*next=curr->children[ch-'a'];
            
            if(next!=NULL)
            {
                prefix.push_back(ch);
                print_suggestions(next,temp,prefix);
                prefix.pop_back();  // backtracking
            }
            else{
                continue;
            }
            
        }
        return ;
        
    }
    vector<vector<string>>getSuggestions(string str)
    {
        // search the character one by one
        
        vector<vector<string>>output;
        
        TrieNode*prev=root;
        
        string prefix="";
        
        int i=0;
        
        for(int i=0;i<str.size();i++)
        {
            
            char lastch=str[i];
            
            prefix.push_back(lastch);
            
            int index=lastch-'a';
            
            TrieNode*curr=prev->children[index];
            
            if(curr==NULL)
            {
                // if not found;
                
                break;
            }
            // if found then print all suggestions
            
            vector<string>temp;
            
            print_suggestions(curr,temp,prefix);
            
            output.push_back(temp);
            
            temp.clear();
            
            prev=curr;
        }
        if( i < str.size())
        {

            while( i < str.size()){

                output.push_back({"0"});
                i++;
                
            }
        }
      return output;
        
    }
    
};
class Solution{
public:

    // NOTE ->  LOVE BABBAR (SOLUTION)
    
    // real life problem of google search engine

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        
        // step 1 -> first make trie of contact list
        
        Trie*t=new Trie();
        
        for(int i=0;i<n;i++)
        {
            string str=contact[i];
            t->insertword(str);
        }
        
        // step 2 -> a string s is given , so we have to search the each character of string s
        // in our given trie;
        
        return t->getSuggestions(s);
        
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends