class Solution {
public:
// typedef 
// typedef pair<int, int> pi;
    int kthSmallest(vector<vector<int>>& matrix, int k)
     
    {
        priority_queue <int, vector<int>, greater<int> > pq;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
            {
                pq.push(matrix[i][j]);
            }
        }
        while(!pq.empty() && k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};