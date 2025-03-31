#define ll long long

class SegTree {
private:
    int sz;
    vector<int> t;

    void upd(int ss, int se, int ni, int i) {
        if (se - ss == 1) {
            t[ni]++;
            return;
        }
        int m = (ss + se) >> 1;
        if (i < m) upd(ss, m, ni * 2 + 1, i);
        else upd(m, se, ni * 2 + 2, i);
        t[ni] = t[ni * 2 + 1] + t[ni * 2 + 2];
    }

    int qry(int l, int r, int ss, int se, int ni) {
        if (l >= se || r <= ss) return 0;
        if (l <= ss && r >= se) return t[ni];
        int m = (ss + se) >> 1;
        return qry(l, r, ss, m, ni * 2 + 1) + qry(l, r, m, se, ni * 2 + 2);
    }

public:
    SegTree(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        t = vector<int>(sz * 2);
    }

    void upd(int i) { upd(0, sz, 0, i); }
    int qry(int l, int r) { return qry(l, r + 1, 0, sz, 0); }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lo, int hi) {
        vector<ll> pre = {0};
        set<ll> s;
        for (const auto& num : nums) pre.push_back(pre.back() + num);
        for (const auto& sum : pre) {
            s.insert(sum);
            s.insert(sum - lo);
            s.insert(sum - hi);
        }
        unordered_map<ll, int> mp;
        int id = 0;
        for (const auto& sum : s) mp[sum] = id++;
        SegTree st(id + 1);
        int ans = 0;
        for (const auto& sum : pre) { 
            int l = mp[sum - hi], r = mp[sum - lo];
            ans += st.qry(l, r);
            st.upd(mp[sum]);
        }
        return ans;
    }
};
