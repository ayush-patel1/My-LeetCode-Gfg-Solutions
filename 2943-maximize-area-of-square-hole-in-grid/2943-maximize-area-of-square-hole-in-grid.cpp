class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int cntV = 1, l = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] == 1) l++;
            else l = 1;
            cntV = max(cntV, l);
        }

        int cntH = 1;
        l = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] == 1) l++;
            else l = 1;
            cntH = max(cntH, l);
        }

        int len = min(cntV, cntH) + 1;
        return len * len;
    }
};
