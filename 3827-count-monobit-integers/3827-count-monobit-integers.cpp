class Solution {
public:
    int countMonobit(int n) {
        int ans = 0;
        for (int i = 0; i <= n; i++) {

            if (i == 0) { 
                ans++; 
                continue; 
            }

            int num = i, cnt = 0;
            for (int j = 0; j < 32; j++) {
                if ((1 << j) & i) {
                    cnt++;
                    num -= (1 << j);
                    if (num == 0) {
                        if (j + 1 == cnt) {
                            ans++;
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
