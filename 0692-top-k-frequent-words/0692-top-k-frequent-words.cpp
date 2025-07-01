/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
public:
class cmp{
    public:
    bool operator() (pair<int,string>&a, pair<int,string>&b)
    {
        if(a.first==b.first)
        {
            if(a.second>b.second){
                return true; // MEANS SWAP VALUES OF PRIORITY QUEUE TO MAKE STRING LEXICOGRAPHICALLY
            }
            else{
                return false; // ALL GOOD NO NEED TO SWAP 
            }
        }
        else{
            if(a.first<b.first){
                return true; // DO SWAPPING
            }
            else{
                return false; // NO SWAPPING
            }
        }
    }
};

vector<string> topKFrequent(vector<string>& words, int k)
{
        unordered_map<string,int>mp;
    
        vector<string>ans;

        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        priority_queue<pair<int,string>,vector<pair<int,string>> ,cmp>pq;

        // priority_queue<pair<int,string>>pq;

        for(auto it:mp){

            pq.push({it.second,it.first}); // PRIORITY QUEUE OF FREQUENCY AND WORDS 
        }

        while(!pq.empty() && k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

    

        return ans;

    
    }
};
// @lc code=end

