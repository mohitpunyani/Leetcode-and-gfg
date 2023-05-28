//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList)
    {
        // Code here
        
        // AYUSI SHARMA (QUEUE VERY EASY APPROACH)
        
        // NOTE ->  SHORTEST WORD INDICATES THAT WE HAVE TO USE BFS
        
        
        //  MAKE A QUEUE WITH A PAIR OF STRING AND STEPS
        
        queue<pair<string,int>>q;
        
        unordered_set<string> dict(wordList.begin(),wordList.end());
        
        q.push({startWord,1});
        
        dict.erase(startWord); // agar hua toh erase ho jayega nahi toh koi dikat nahi hai.
        
        
        while(!q.empty()){
            
            auto top=q.front();
            
            string word=top.first;
            
            int steps=top.second;
            
            if(word==targetWord){
                return steps;
            }
            q.pop();
            
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                
                for(char ch='a';ch<='z';ch++)
                {
                
                    word[i]=ch;
                    
                    if(dict.find(word)!=dict.end())
                    {
                        q.push({word,steps+1});
                        dict.erase(word);
                        
                        
                    }
                    else{
                        continue;
                    }
                    
                }
                // don't change the word;
                word[i]=original; // initialize with previous character
                
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends