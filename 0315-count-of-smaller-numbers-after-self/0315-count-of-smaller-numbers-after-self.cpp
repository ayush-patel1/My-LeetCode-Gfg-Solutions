class Solution {
public:
    void merge(int l, int mid, int r, vector<pair<int,int>>& p, vector<int>& res) {
        vector<pair<int,int>> temp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (p[i].first <= p[j].first) {
                res[p[i].second] += (j - (mid + 1));
                temp.push_back(p[i++]);
            } else {
                temp.push_back(p[j++]);
            }
        }
        while (i <= mid) {
            res[p[i].second] += (j - (mid + 1));
            temp.push_back(p[i++]);
        }
        while (j <= r) {
            temp.push_back(p[j++]);
        }
        for (int k = 0; k < temp.size(); k++) p[l + k] = temp[k];
    }

    void mergeSort(int l, int r, vector<pair<int,int>>& p, vector<int>& res) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(l, mid, p, res);
            mergeSort(mid + 1, r, p, res);
            merge(l, mid, r, p, res);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> p(n);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) p[i] = {nums[i], i};
        if (n > 0) mergeSort(0, n - 1, p, res);
        return res;
    }
};



//didn't work for last three cases TLE

// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         multiset<int> st;
//         vector<int> res(n, 0);

//         st.insert(nums.back());

//         for (int i = n - 2; i >= 0; i--) {

//             auto idx = st.lower_bound(nums[i]);

//             if (idx == st.begin()) {
//                 res[i] = 0;
//             } else {
//                 while (idx != st.begin() && *idx == nums[i]) idx--;
//                 res[i] = distance(st.begin(), idx) + 1;
//             }

//             st.insert(nums[i]);
//         }

//         return res;
//     }
// };
