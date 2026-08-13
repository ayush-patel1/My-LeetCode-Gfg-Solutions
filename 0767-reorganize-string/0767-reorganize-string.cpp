class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], i + 'a'});
            }
        }

        string ans = "";
        while (maxHeap.size() > 1) {
            pair<int, char> a = maxHeap.top(); maxHeap.pop();
            pair<int, char> b = maxHeap.top(); maxHeap.pop();
            
            ans += a.second;
            ans += b.second;
            
            a.first--;
            b.first--;

            if (a.first > 0) maxHeap.push(a);
            if (b.first > 0) maxHeap.push(b);
        }

        if (!maxHeap.empty()) {
            auto last = maxHeap.top();
            if (last.first > 1) {
                return "";
            }
            ans += last.second;
        }

        return ans;
    }
};