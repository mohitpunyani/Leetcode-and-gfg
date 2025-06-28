#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
// problem next greater element to left
   stack<pair<int,int>>st; // contain element and index
   int index;
    StockSpanner() 
    {
        index=0;        
    }
    int next(int price) 
    {
        index=index+1;
        while(!st.empty() && price>=st.top().first)
        {
            st.pop();
        }
        int result=st.empty() ? index : index-st.top().second;
        st.push({price,index});
        return result;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */