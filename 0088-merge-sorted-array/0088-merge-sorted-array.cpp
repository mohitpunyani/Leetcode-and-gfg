class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        // brute force

        // int i=0;
        // while(i<n){
        //     nums1[m+i]=nums2[i];
        //     i++;
        // }
        // sort(nums1.begin(),nums1.end());
        
        // optimized
        vector<int>temp(m+n);

        int i=0;
        int j=0;
        int k=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                temp[k]=nums1[i];
                i++;
                k++;
            }
            else{
                temp[k]=nums2[j];
                j++;
                k++;
            }
        }
        
        while(j<n){
            temp[k]=nums2[j];
            j++;
            k++;
        }
        while(i<m){
            temp[k]=nums1[i];
            i++;
            k++;
        }
        nums1=temp;
    }
};