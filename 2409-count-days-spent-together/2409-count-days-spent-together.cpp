class Solution {
public:
    int solve(string s, vector<int>& days) {
        int m = stoi(s.substr(0, 2));
        int d = stoi(s.substr(3, 2));

        for (int i = 0; i < m - 1; i++) {
            d += days[i];
        }

        return d;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        int a = solve(arriveAlice, days);
        int b = solve(leaveAlice, days);
        int c = solve(arriveBob, days);
        int d = solve(leaveBob, days);

        return max(0, min(b, d) - max(a, c) + 1);
    }
};