class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int min_idx = 0, a_penalty = 0;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'N')
                a_penalty += 1;
        }
        int min_penalty = a_penalty;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'N')
                a_penalty++;
            else
                a_penalty--;
            if (min_penalty > a_penalty) {
                min_penalty = a_penalty;
                min_idx = i + 1;
            }
        }
        return min_idx;
    }
};