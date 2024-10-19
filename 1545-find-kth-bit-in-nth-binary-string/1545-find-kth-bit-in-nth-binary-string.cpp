class Solution {
public:
    char findKthBit(int n, int k) {
        string temp = "0";
        vector<string> arr(n);
        arr[0] = "0";
        for (int i = 1; i < n; i++) {
            arr[i] = temp + "1";
            for (int j = temp.size() - 1; j >= 0; j--) {
                if (temp[j] == '1') {
                    arr[i] += "0";
                } else {
                    arr[i] += "1";
                }
            }
            temp = arr[i];
        }
        return arr[n - 1][k - 1];
    }
};
