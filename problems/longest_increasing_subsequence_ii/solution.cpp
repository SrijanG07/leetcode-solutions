class Solution {
public:
    int query(int index, int s, int e, int l, int r, vector<int> &tree) {
        if (s > r || e < l) {
            return 0;
        }
        if (s >= l && e <= r) {
            return tree[index];
        }
        
        int mid = (s + e) / 2;
        int left = 2 * index;
        int right = 2 * index + 1;
        int lans = query(left, s, mid, l, r, tree);
        int rans = query(right, mid + 1, e, l, r, tree);
        return max(lans, rans);
    }

    void update(int index, int s, int e, int pos, int val, vector<int> &tree) {
        if (s == e) {
            tree[index] = val;
            return;
        }

        int mid = (s + e) / 2;
        if (pos <= mid) {
            update(2 * index, s, mid, pos, val, tree);
        } else {
            update(2 * index + 1, mid + 1, e, pos, val, tree);
        }

        tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        int n = 1e5 + 2;
        vector<int> tree(4 * n + 5, 0); 
        
        for (int it : nums) {
            int l = max(0, it - k);
            int maxi = query(1, 0, n - 1, l, it - 1, tree);
            int cur = 1 + maxi;
            update(1, 0, n - 1, it, cur, tree);
        }

        return tree[1];
    }
};
