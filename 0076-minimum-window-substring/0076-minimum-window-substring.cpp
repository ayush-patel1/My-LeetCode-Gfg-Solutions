class Solution {
public:
    

string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";
    
    unordered_map<char, int> freq_t;
    for (char c : t) {
        freq_t[c]++;
    }
    
    unordered_map<char, int> window_count;
    int have = 0, need = freq_t.size();
    int left = 0, right = 0;
    int min_length = INT_MAX;
    int start = 0;  
    
    while (right < s.size()) {
        char c = s[right];
        window_count[c]++;
        
        if (freq_t.find(c) != freq_t.end() && window_count[c] == freq_t[c]) {
            have++;
        }
        
        while (have == need) {
           
            if (right - left + 1 < min_length) {
                min_length = right - left + 1;
                start = left;
            }
            
            char left_char = s[left];
            window_count[left_char]--;
            
            if (freq_t.find(left_char) != freq_t.end() && window_count[left_char] < freq_t[left_char]) {
                have--;
            }
            
            left++; 
        }
        
        right++; 
    }
    
    return min_length == INT_MAX ? "" : s.substr(start, min_length);
}

};