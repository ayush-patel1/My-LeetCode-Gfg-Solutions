class node {
public:
    int lsum, rsum;

    node() {
        lsum = rsum = 0;
    }
    node(int val) {
        lsum = rsum = val;
    }
};

vector<node> t;
int n;

node merge(node &a, node &b, int lenL, int lenR) {
    node c;
    c.lsum = a.lsum;
    if (a.lsum == lenL)
        c.lsum = a.lsum + b.lsum;

    c.rsum = b.rsum;
    if (b.rsum == lenR)
        c.rsum = b.rsum + a.rsum;

    return c;
}

void update(int idx, int l, int r, int pos) {
    if (l == r) {
        t[idx] = node(1);
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2*idx+1, l, mid, pos);
    else
        update(2*idx+2, mid+1, r, pos);

    int lenL = mid - l + 1;
    int lenR = r - mid;

    t[idx] = merge(t[2*idx+1], t[2*idx+2], lenL, lenR);
}

class LUPrefix {
public:
    LUPrefix(int _n) {
        n = _n;
        t.assign(4*n, node(0));
    }

    void upload(int video) {
        update(0, 0, n-1, video-1);
    }

    int longest() {
        return t[0].lsum;
    }
};


/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */