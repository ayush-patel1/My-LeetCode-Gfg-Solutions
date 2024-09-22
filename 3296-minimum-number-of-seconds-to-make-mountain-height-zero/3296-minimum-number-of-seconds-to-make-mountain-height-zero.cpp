class Solution {
public:
    long long timeTotal(int height, int wTime) {
        return static_cast<long long>(height) * (height + 1) / 2 * wTime;
    }
    bool isPossible(long long time, int mountainHeight, const vector<int>& workerTimes) {
        long long totalHeight = 0;
        for (long long wTime : workerTimes) {
            double workerHeight = (-1 + sqrt(1 + 8.0 * time / wTime)) / 2;
            totalHeight += static_cast<int>(workerHeight);
            if (totalHeight >= mountainHeight) {
                return true;
            }
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0;
        long long right = 1e18;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (isPossible(mid, mountainHeight, workerTimes)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};