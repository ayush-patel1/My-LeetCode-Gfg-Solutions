class Solution {
public:
    const int MAX = 1001;
    vector<int> isPrime = vector<int>(1001, 1);

    void pre() {
        isPrime[0] = isPrime[1] = 0;
        for (int i = 0; i <= 1000; i++) {
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime[i] = 0;
                    break;
                }
            }
        }
    }

    int sumOfPrimesInRange(int n) {
        pre();
        string s = to_string(n);
        reverse(s.begin(),s.end());
        cout<<s;
        int r = stoi(s);

        int sum = 0;
        for (int i = min(n, r); i <= max(n, r); i++) {
            if (isPrime[i]) sum += i;
        }
        return sum;
    }
};