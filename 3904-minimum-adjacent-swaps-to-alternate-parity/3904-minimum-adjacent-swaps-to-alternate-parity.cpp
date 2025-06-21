// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int n = nums.size();
        
//         // Count even and odd numbers
//         int evenCount = 0, oddCount = 0;
//         for (int num : nums) {
//             if (num % 2 == 0) evenCount++;
//             else oddCount++;
//         }
        
//         // Check if it's possible to create alternating pattern
//         if (abs(evenCount - oddCount) > 1) return -1;
        
//         // Try pattern 1: even at even indices (0, 2, 4, ...)
//         int swaps1 = INT_MAX;
//         if (evenCount >= (n + 1) / 2 && oddCount >= n / 2) {
//             vector<int> temp = nums;
//             swaps1 = calculateSwaps(temp, 0); // 0 means even at even indices
//         }
        
//         // Try pattern 2: odd at even indices (0, 2, 4, ...)
//         int swaps2 = INT_MAX;
//         if (oddCount >= (n + 1) / 2 && evenCount >= n / 2) {
//             vector<int> temp = nums;
//             swaps2 = calculateSwaps(temp, 1); // 1 means odd at even indices
//         }
        
//         int result = min(swaps1, swaps2);
//         return result == INT_MAX ? -1 : result;
//     }
    
// private:
//     int calculateSwaps(vector<int>& nums, int startParity) {
//         int n = nums.size();
//         vector<int> evenPos, oddPos;
        
//         // Collect positions of even and odd numbers
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % 2 == 0) {
//                 evenPos.push_back(i);
//             } else {
//                 oddPos.push_back(i);
//             }
//         }
        
//         int swaps = 0;
        
//         // For each position, check if it has correct parity
//         for (int i = 0; i < n; i++) {
//             int expectedParity = (i + startParity) % 2;
            
//             if (expectedParity == 0) { // Need even number at position i
//                 if (nums[i] % 2 == 1) { // But we have odd
//                     // Find the closest even number to the right
//                     int evenIdx = -1;
//                     for (int j = 0; j < evenPos.size(); j++) {
//                         if (evenPos[j] > i) {
//                             evenIdx = evenPos[j];
//                             evenPos.erase(evenPos.begin() + j);
//                             break;
//                         }
//                     }
                    
//                     if (evenIdx != -1) {
//                         // Count swaps needed to bring this even number to position i
//                         swaps += evenIdx - i;
                        
//                         // Update positions of odd numbers that got shifted
//                         for (int& pos : oddPos) {
//                             if (pos > i && pos < evenIdx) {
//                                 pos++;
//                             }
//                         }
                        
//                         // Update the array
//                         int temp = nums[evenIdx];
//                         for (int k = evenIdx; k > i; k--) {
//                             nums[k] = nums[k-1];
//                         }
//                         nums[i] = temp;
//                     }
//                 }
//             } else { // Need odd number at position i
//                 if (nums[i] % 2 == 0) { // But we have even
//                     // Find the closest odd number to the right
//                     int oddIdx = -1;
//                     for (int j = 0; j < oddPos.size(); j++) {
//                         if (oddPos[j] > i) {
//                             oddIdx = oddPos[j];
//                             oddPos.erase(oddPos.begin() + j);
//                             break;
//                         }
//                     }
                    
//                     if (oddIdx != -1) {
//                         // Count swaps needed to bring this odd number to position i
//                         swaps += oddIdx - i;
                        
//                         // Update positions of even numbers that got shifted
//                         for (int& pos : evenPos) {
//                             if (pos > i && pos < oddIdx) {
//                                 pos++;
//                             }
//                         }
                        
//                         // Update the array
//                         int temp = nums[oddIdx];
//                         for (int k = oddIdx; k > i; k--) {
//                             nums[k] = nums[k-1];
//                         }
//                         nums[i] = temp;
//                     }
//                 }
//             }
//         }
        
//         return swaps;
//     }
// };


class Solution{
public:
int minSwaps(vector<int>& nums) {
    int n = nums.size();
    vector<int> evenIdx, oddIdx;
    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 == 0) evenIdx.push_back(i);
        else oddIdx.push_back(i);
    }
    if (abs((int)evenIdx.size() - (int)oddIdx.size()) > 1) return -1;
    long long res = LLONG_MAX;
    if (evenIdx.size() >= oddIdx.size()) {
        long long swaps = 0;
        for (int i = 0; i < evenIdx.size(); ++i) swaps += abs(evenIdx[i] - 2 * i);
        res = min(res, swaps);
    }
    if (oddIdx.size() >= evenIdx.size()) {
        long long swaps = 0;
        for (int i = 0; i < oddIdx.size(); ++i) swaps += abs(oddIdx[i] - 2 * i);
        res = min(res, swaps);
    }
    return (int)res;
}
};