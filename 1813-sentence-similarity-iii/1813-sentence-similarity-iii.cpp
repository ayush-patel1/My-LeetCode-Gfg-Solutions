class Solution {
public:
    // Helper function to split a sentence into a vector of words
    vector<string> splitSentence(const string &s) {
        vector<string> result;
        string temp = "";
        for (char c : s) {
            if (c != ' ') {
                temp += c;
            } else {
                result.push_back(temp);
                temp = "";
            }
        }
        result.push_back(temp);  // Add the last word
        return result;
    }
    
    bool solve(const vector<string> &s1_arr, const vector<string> &s2_arr) {
        int left1 = 0, left2 = 0;
        int right1 = s1_arr.size() - 1;
        int right2 = s2_arr.size() - 1;
        
        // Compare words from both left and right, but ensure the match is consistent
        while (left1 <= right1 && left2 <= right2) {
            if (s1_arr[left1] == s2_arr[left2]) {
                left1++;
                left2++;
            } else if (s1_arr[right1] == s2_arr[right2]) {
                right1--;
                right2--;
            } else {
                // Break if no valid match can be made
                return false;
            }
        }
        
        return true;
    }

    // Main function to check if the sentences are similar
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1_arr = splitSentence(sentence1);
        vector<string> s2_arr = splitSentence(sentence2);
        
        // Check sentence similarity only if the smaller sentence can be formed from the larger one
        if (s1_arr.size() >= s2_arr.size()) {
            return solve(s1_arr, s2_arr);
        } else {
            return solve(s2_arr, s1_arr);
        }
    }
};
