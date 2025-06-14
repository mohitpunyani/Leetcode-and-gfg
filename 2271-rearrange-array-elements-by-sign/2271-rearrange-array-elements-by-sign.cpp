class Solution
{
    public:
        vector<int> rearrangeArray(vector<int> &nums)
        {
           	//  APPROACH 1 - brute force

           	//     vector < int>pos;
           	//     vector < int>neg;
           	//     vector < int>ans;
           	//     int sz=nums.size();
           	//     for(int i=0;i < sz;i++){
           	//         if(nums[i]>=0){
           	//             pos.push_back(nums[i]);
           	//         }
           	//     }
           	//     for(int i=0;i < sz;i++){
           	//         if(nums[i] < 0){
           	//             neg.push_back(nums[i]);
           	//         }
           	//     }
           	//     sz=pos.size();
           	//     for(int i=0;i < sz;i++)
           	//     {
           	//         ans.push_back(pos[i]);
           	//         ans.push_back(neg[i]);

           	//     }
           	//     return ans;
           	// }

           	// APPROACH 2-  use only one array

            // int sz = nums.size();
            // int j = 0;
            // int k = sz - 1;
            // vector<int> posneg(sz);
            // vector<int> temp;
            // for (int i = 0; i < sz; i++)
            // {
            //     if (nums[i] >= 0)
            //     {
            //         posneg[j] = nums[i];
            //         j++;
            //     }
            //     else
            //     {
            //         posneg[k] = nums[i];
            //         k--;
            //     }
            // }
            // for (int i = 0; i < sz/2; i++)
            // {
            //     temp.push_back(posneg[i]);
            //     temp.push_back(posneg[sz - i - 1]);
            // }
            // return temp;

            // APPROACH 3 - NO EXTRA SPACE

            int n=nums.size();
            int pos_idx=0;
            int neg_idx=1;
            vector<int>ans(n);
            for(int i=0;i<n;i++){
                if(nums[i]>=0)
                {
                    ans[pos_idx]=nums[i];
                    pos_idx=pos_idx+2;
                }
                else{
                    ans[neg_idx]=nums[i];
                    neg_idx=neg_idx+2;
                }
            }
            return ans;
        }
    };