class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Map to store the first occurrence of each bitmask state
        unordered_map<int, int> seen;
        seen[0] = -1; // The empty prefix (before the string starts) corresponds to state 0
        
        int mask = 0; // Bitmask to track vowel parity
        int max_len = 0;
        
        // Iterate over the string
        for (int i = 0; i < s.size(); ++i) {
            // Update the bitmask based on the current character
            if (s[i] == 'a') mask ^= (1 << 0);
            if (s[i] == 'e') mask ^= (1 << 1);
            if (s[i] == 'i') mask ^= (1 << 2);
            if (s[i] == 'o') mask ^= (1 << 3);
            if (s[i] == 'u') mask ^= (1 << 4);
            
            // If this mask has been seen before, calculate the length of the substring
            if (seen.count(mask)) {
                max_len = max(max_len, i - seen[mask]);
            } else {
                // Otherwise, store the first occurrence of this mask
                seen[mask] = i;
            }
        }
        
        return max_len;
    }
};
