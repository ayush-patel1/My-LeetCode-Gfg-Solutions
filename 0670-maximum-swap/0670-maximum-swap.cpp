class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int maxi_ind = n - 1;
        int bad_ind = -1, swap_ind = -1;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] < s[i + 1]) {
                bad_ind = i;
                break;
            }
        }

     
        if (bad_ind == -1) {
            return num;
        }

        
        for (int i = bad_ind + 1; i < n; i++) {
            if (s[i] >= s[maxi_ind]) {
                maxi_ind = i;
            }
        }

     
        for (int i = 0; i <= bad_ind; i++) {
            if (s[i] < s[maxi_ind]) {
                swap_ind = i;
                break;
            }
        }

 
        swap(s[swap_ind], s[maxi_ind]);

      
        return stoi(s);
    }
};
