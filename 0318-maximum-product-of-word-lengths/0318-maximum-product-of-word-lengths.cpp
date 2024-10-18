class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> val(n);
        for (int i = 0; i < n; i++) {
            int res = 0;
            for (char c : words[i]) {
                res |= (1 << (c - 'a'));
            }
            val[i] = res;
        }
      int maxi = 0;
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if ((val[i] & val[j]) == 0) {
            int product = words[i].size() * words[j].size();  
            maxi = max(maxi, product);  
        }
    }
}
return maxi;
    
    }
};