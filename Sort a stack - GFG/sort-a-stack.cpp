//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends




/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

// SAME APPROACH AS REVERSE OF STACK 


void insert(stack<int> &s,int &top)
{
    if(s.size()==0 || s.top()<top){
        s.push(top);
        return ;
    }
    int temp=s.top();
    s.pop();
    insert(s,top);
    s.push(temp);
    return ;
}
void sortstack(stack<int> &s){
    if(s.empty())
    {
        return ;
    }
    int top=s.top();
    s.pop();
    sortstack(s);
    insert(s,top);
    return ;
    
    
}

void SortedStack :: sort()
{
   //Your code here
   sortstack(s);
}