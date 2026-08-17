#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int minJumps(std::vector<int>& arr) {
        int n = arr.size();
        
        // Base case: if array has only 1 element, we're already at the end.
        if (n <= 1) return 0;
        
        // Map to store all indices for a specific value: value -> [index1, index2, ...]
        std::unordered_map<int, std::vector<int>> value_to_indices;
        for (int i = 0; i < n; ++i) {
            value_to_indices[arr[i]].push_back(i);
        }
        
        // Visited array to prevent infinite loops
        std::vector<bool> visited(n, false);
        visited[0] = true;
        
        // Queue stores indices, not values
        std::queue<int> q;
        q.push(0);
        
        int steps = 0;
        
        // BFS traversal
        while (!q.empty()) {
            int size = q.size();
            
            // Process all nodes at the current level
            for (int k = 0; k < size; ++k) {
                int curr = q.front();
                q.pop();
                
                // If we reached the last index, return the current step count
                if (curr == n - 1) {
                    return steps;
                }
                
                // 1. Check jump to i - 1
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                
                // 2. Check jump to i + 1
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                
                // 3. Check jumps to j where arr[curr] == arr[j]
                if (value_to_indices.count(arr[curr])) {
                    for (int next_idx : value_to_indices[arr[curr]]) {
                        if (!visited[next_idx]) {
                            visited[next_idx] = true;
                            q.push(next_idx);
                        }
                    }
                    // CRUCIAL OPTIMIZATION: Erase the processed value from the map.
                    // This prevents redundant lookups and prevents a Time Limit Exceeded (TLE) error.
                    value_to_indices.erase(arr[curr]);
                }
            }
            // Increment steps after finishing the current level
            steps++;
        }
        
        return -1; 
    }
};