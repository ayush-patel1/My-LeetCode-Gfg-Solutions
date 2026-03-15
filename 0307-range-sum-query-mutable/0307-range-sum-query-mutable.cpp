#include <vector>
using namespace std;

class NumArray {
    vector<int> seg;
    int n;

    void build(vector<int>& nums, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        build(nums, 2 * idx + 1, l, m);
        build(nums, 2 * idx + 2, m + 1, r);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateTree(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) updateTree(2 * idx + 1, l, m, pos, val);
        else updateTree(2 * idx + 2, m + 1, r, pos, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int m = (l + r) / 2;
        return query(2 * idx + 1, l, m, ql, qr) + query(2 * idx + 2, m + 1, r, ql, qr);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */