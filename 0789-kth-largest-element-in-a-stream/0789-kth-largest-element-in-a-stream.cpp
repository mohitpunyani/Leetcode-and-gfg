class KthLargest {
public:
     priority_queue<int,vector<int>,greater<int>>mnheap;
    int num;
    KthLargest(int k, vector<int>& nums) 
    {
        num = k; 
        for(int i=0;i<nums.size();i++)
        {
            mnheap.push(nums[i]);
        }   
        while(!mnheap.empty() && mnheap.size()>k)
        {
            mnheap.pop();
        }
    }
    
    int add(int val)
    {
        mnheap.push(val);
        if(mnheap.size() > num) mnheap.pop();
        return mnheap.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */