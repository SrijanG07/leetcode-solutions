class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;   

        int pref = 0;
        int ans = 0;

        for (int x : nums) {
            pref += x;

            if (freq.count(pref - k)) {
                ans += freq[pref - k];
            }

            freq[pref]++;
        }

        return ans;
    }
};
