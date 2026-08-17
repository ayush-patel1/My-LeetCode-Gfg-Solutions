class Solution {
public:
//always choose maxGreen as max elem in lights as it will allow more number //of r to be less than maxGreen . so its always optimal
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();
        int m = *max_element(lights.begin(), lights.end());
        int mx = 0;

        for (int i = 0; i < n; i++) {
            int r = arrivalTime[i] % period;

            if (r >= m) {
                mx = max(mx, period - r);
            }
        }

        return mx;
    }
};