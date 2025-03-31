class BIT {
public:
    vector<int> bit;
    BIT(int size): bit(size + 1) {}
    
    void add(int idx, int val) {
        idx += 1;
        while (idx < this -> bit.size()) {
            this -> bit[idx] += val;
            idx += idx & -idx;
        }
    }
    
    int query(int idx) {
        idx += 1;
        int s = 0;
        while (idx > 0) {
            s += this -> bit[idx];
            idx -= idx & -idx;
        }
        return s;
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        set<int> tmp;
        vector<int> nums;
        for (int i = 0; i < nums1.size(); i+=1) {
            nums.emplace_back(nums1[i] - nums2[i]);
            tmp.emplace(nums1[i] - nums2[i]);
            tmp.emplace(nums1[i] - nums2[i] + diff);
        }
        
        unordered_map<int, int> mapping;
        int i = 0;
        for (auto& n: tmp) {
            mapping.emplace(n, i);
            i += 1;
        }
        
        long long ans = 0;
        BIT bit(mapping.size());
        
        for (int& n: nums) {
            ans += bit.query(mapping[n + diff]);
            bit.add(mapping[n], 1);
        }
        
        return ans;
    }
};