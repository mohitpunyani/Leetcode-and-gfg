class Solution {
  public:
    // Function to find triplets with zero sum.
    bool findTriplets(vector<int> &arr)
    {
        // code here
        
     int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0) {
                return true;
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                right--;
            }
        }
    }
    return false;
            
    
    }
};