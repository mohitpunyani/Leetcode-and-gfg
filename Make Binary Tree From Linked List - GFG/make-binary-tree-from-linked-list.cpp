//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
    if (r == NULL) return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left) q.push(j->left);
        if (j->right) q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) cout << "-1\n";
        lvl(root);
        cout << endl;
        // inorder(root);
        getchar();
    }
    return 0;
}

// } Driver Code Ends


/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

//Function to make binary tree from linked list.

// TreeNode*recursive(TreeNode*root,vector<int>&v,int p){
    
//     if(p>=v.size()){
//         return NULL;
//     }
//     root=new TreeNode(v[p]);
    
//     root->left=recursive(root->left,v,(2*p)+1);
//     root->right=recursive(root->right,v,(2*p)+2);
//     return root;
// }
void convert(Node *head, TreeNode *&root) 
{
    // 1.  recursive approach 
    
    // similar to make binary tree from array 
    
    // convert linked list to array 
    
    // vector<int>v;
    // while(head!=NULL){
    //     v.push_back(head->data);
    //     head=head->next;
    // }
    // int parent=0;
    // root=recursive(root,v,parent);
    
    // 2. iterative approach using bfs
    
    // root = new TreeNode(head->data);
    
    // head = head->next;
    // queue<TreeNode*> q;
    // q.push(root);
    // while(head!=NULL && !q.empty()){
    //     TreeNode* curr = q.front();
    //     q.pop();
    //     curr->left = new TreeNode(head->data);
    //     q.push(curr->left);
    //     head = head->next;
    //     if(head){
    //         curr->right = new TreeNode(head->data);
    //         q.push(curr->right);
    //         head = head->next;
    //     }
    // }
    
      queue<TreeNode*> q;
    root = new TreeNode(head->data);
    q.push(root);
    
    Node* ptr = head->next;
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        
        if(ptr){
            temp->left = new TreeNode(ptr->data);
            q.push(temp->left);
            ptr = ptr->next;
        }
        
        if(ptr){
            temp->right = new TreeNode(ptr->data);
            q.push(temp->right);
            ptr = ptr->next;
        }
        else{
            break;
        }
        
    }

}
