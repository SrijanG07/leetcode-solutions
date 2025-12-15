class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int wind = 0;
        int ans = 0;
        for (int i = 0; i<nums.size() ; i++) {
            wind++;
            if (nums[i] == 0) {
                ans = max(ans,wind-1);
                wind = 0;
            }
        }
        return max(ans,wind);
    }
};