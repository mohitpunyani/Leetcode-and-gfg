class Solution
{
    public:
        vector<int> rearrangeArray(vector<int> &nums)
        {
           	// brute force

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

           	// use only one array

            int sz = nums.size();
            int j = 0;
            int k = sz - 1;
            vector<int> posneg(sz);
            vector<int> temp;
            for (int i = 0; i < sz; i++)
            {
                if (nums[i] >= 0)
                {
                    posneg[j] = nums[i];
                    j++;
                }
                else
                {
                    posneg[k] = nums[i];
                    k--;
                }
            }
            for (int i = 0; i < sz/2; i++)
            {
                temp.push_back(posneg[i]);
                temp.push_back(posneg[sz - i - 1]);
            }
            return temp;
        }
    };