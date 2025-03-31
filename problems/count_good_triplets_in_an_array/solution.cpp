class SegmentTree {
public:
    vector<long> seg;
    int n;

    SegmentTree(int size) {
        n = size;
        seg.resize(4 * n + 1, 0);
        build(1, n, 1);
    }

    void build(int l, int r, int c) {
        if (l == r) {
            seg[c] = 0;
            return;
        }
        int mid = l + (r - l) / 2;
        build(l, mid, 2 * c);
        build(mid + 1, r, 2 * c + 1);
        seg[c] = seg[2 * c] + seg[2 * c + 1];
    }

    long query(int l, int r, int a, int b, int c) {
        if (l > b || r < a) {
            return 0;
        }
        if (l >= a && r <= b) {
            return seg[c];
        }
        int mid = l + (r - l) / 2;
        return query(l, mid, a, b, 2 * c) + query(mid + 1, r, a, b, 2 * c + 1);
    }

    void update(int l, int r, int ind, int c) {
        if (ind < l || r < ind) {
            return;
        }
        if (l == r && l == ind) {
            seg[c] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        update(l, mid, ind, 2 * c);
        update(mid + 1, r, ind, 2 * c + 1);
        seg[c] = seg[2 * c] + seg[2 * c + 1];
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ans = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[nums2[i] + 1] = i + 1;
        }

        SegmentTree tree(n);
        for (int i = 1; i <= n; i++) {
            long r = map[nums1[i - 1] + 1];
            long q = tree.query(1, n, 1, r, 1);
            long d = i - q - 1;
            long e = n - r - d;
            ans += e * q;
            tree.update(1, n, r, 1);
        }

        return ans;
    }
};
