//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// } Driver Code Ends
class Solution
{

    public:
   void insertattail(Node* &head,Node*&tail,int d)
    {
        Node*newnode=new Node(d);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            return ;
            
        }
        else{
            tail->next=newnode;
            tail=tail->next; // or tail=newnode;
        }
    }
    Node *copyList(Node *head)
    {
        // NOTE-> THIS IS MY SOLUTION 
        // step1 create a clone list of next pointer.
        Node*clonehead=NULL;
        Node*clonetail=NULL;
        
        Node*temp1=head;
        while(temp1!=NULL){
            insertattail(clonehead,clonetail,temp1->data);
            temp1=temp1->next;
        }
        
        // step2 clone node ko original list me add kar do.
         // step 2 -> insert head of clone linked list between the two nodes of copy linked list
        
//         // STEP 2 IS IMPORTANT FOR THINKING
        
        Node*originalnode=head;
        Node*clonenode=clonehead;
        
        while(originalnode!=NULL && clonenode!=NULL)
        {
           Node*temp=originalnode->next;
           originalnode->next=clonenode;
           Node*temp1=clonenode->next;
           clonenode->next=temp;
           originalnode=temp;
           clonenode=temp1;
        }
        // step 3 make a link of random pointer of clone node. or copy the random pointer
        
                 // step3 -> with the help of step2 we can link the random pointer of the clone 
        
//         // ab is step me we have to play with random pointer
    
          Node*temp=head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL && temp->arb!=NULL )
            {
                if(temp->arb!=NULL)
                {
                    
                temp->next->arb=temp->arb->next;
                }
    
            else{
                temp->next=temp->arb;
            }
        }
            temp=temp->next->next;
        }
        // step 4 revert changes done in step2 
        
                 // // or  the main reason to do step 2 is to copy the random pointer 
        
//         // // step 4 -> revert changes of step 2 because question said that we can't do change in
        
//         // // the original list or in step 2 we break the next links of copy linked list 
        
//         // // so we have to make it again 
        
        originalnode=head;
        clonenode=clonehead;
        while(originalnode!=NULL && clonenode!=NULL){
            originalnode->next=clonenode->next;
            originalnode=originalnode->next;
            
            if(originalnode!=NULL)
            {
                clonenode->next=originalnode->next;
            }   
            clonenode=clonenode->next;
        }
        // step 5 return ans
        return clonehead;
    }

};

//{ Driver Code Starts.


void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}


void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {


    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}



int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
// } Driver Code Ends