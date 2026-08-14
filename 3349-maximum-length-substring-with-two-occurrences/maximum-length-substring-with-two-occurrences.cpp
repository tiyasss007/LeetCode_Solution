#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        // Frequency array to count occurrences of each character (a-z)
        std::vector<int> freq(26, 0);
        int max_len = 0;
        int left = 0;
        
        // Expand the window by moving the right pointer
        for (int right = 0; right < s.length(); ++right) {
            freq[s[right] - 'a']++;
            
            // If the current character appears more than twice, 
            // shrink the window from the left until it's valid again
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }
            
            // Calculate the maximum length found so far
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};