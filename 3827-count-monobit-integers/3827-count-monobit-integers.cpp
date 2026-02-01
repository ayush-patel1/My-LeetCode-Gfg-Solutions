class Solution {
public:
    int countMonobit(int n) {
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            int num = i, cnt = 0;
            for (int j = 0; j < 32; j++) {
                if ((1 << j) & i) {
                    cnt++;
                    num -= (1 << j);
                    if (num == 0) {
                        if (j + 1 == cnt || cnt == 0) {
                            ans++;
                        }
                        break;
                    }
                }
            }
        }
        return ++ans;
    }
};
