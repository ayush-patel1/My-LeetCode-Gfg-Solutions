class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char c : tasks)
            freq[c - 'A']++;

        priority_queue<int> pq;

        for (int x : freq)
            if (x)
                pq.push(x);

        int ans = 0;

        while (!pq.empty()) {
            vector<int> rem;
            int cnt = 0;

            for (int i = 0; i <= n && !pq.empty(); i++) {
                int f = pq.top();
                pq.pop();

                f--;
                cnt++;

                if (f > 0)
                    rem.push_back(f);
            }

            for (int x : rem)
                pq.push(x);

            if (pq.empty())
                ans += cnt;
            else
                ans += n + 1;
        }

        return ans;
    }
};