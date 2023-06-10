/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* clone_graph(Node* curr,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*>neighbours;
        
        Node* clone=new Node(curr->val);
        
        mp[curr]=clone;
        
        for(auto it:curr->neighbors){
            if(mp.find(it)!=mp.end())
            {
                neighbours.push_back(mp[it]);
                
            }
            else if(mp.find(it)==mp.end())
            {
                // call for dfs
                neighbours.push_back(clone_graph(it,mp));
            }
        }
        
        clone->neighbors=neighbours;
        return clone;
        
    }
    
    Node* cloneGraph(Node* node)
    {
        
        // ayushi sharma
        
        unordered_map<Node*,Node*>mp;  
        
        // make a map **
        // OLD NODE AND CLONE NODE
        
        if(node==NULL)
        {
            return NULL;
            
        }
        // we have only single node
        if(node->neighbors.size()==0)
        {
            Node* clone=new Node(node->val);
            return clone;
        }
        return clone_graph(node,mp);
        
    }
};