class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char t : tasks) count[t - 'A']++;
        sort(count.begin(), count.end());
        int max_freq = count[25];
        int tasks_with_max_freq = 0;
        for (int i = 25; i >= 0; i--) {
            if (count[i] != max_freq) break;
            tasks_with_max_freq++;
        }
        return max((int)tasks.size(), (max_freq - 1) * (n + 1) + tasks_with_max_freq);
    }
};