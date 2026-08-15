#include <vector>

class Solution {
public:
    int longestSubsequence(std::vector<int>& nums) {
        int total_xor = 0;
        bool has_nonzero = false;
        
        // Calculate the total XOR and check for any non-zero element
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                has_nonzero = true;
            }
        }
        
        // Case 1: Total XOR is already non-zero
        if (total_xor != 0) {
            return nums.size();
        } 
        // Case 2: Total XOR is 0, but we can remove one non-zero element
        else if (has_nonzero) {
            return nums.size() - 1;
        } 
        // Case 3: Array is filled with entirely 0s
        else {
            return 0;
        }
    }
};