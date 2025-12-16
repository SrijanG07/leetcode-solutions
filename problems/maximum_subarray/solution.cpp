class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefsum(n+1, 0);
        
        for (int i = 0; i < n; i++)
            prefsum[i+1] = prefsum[i] + nums[i];
        
        int maxSum = nums[0]; 
        int minPrefix = 0;      
        
        for (int i = 1; i <= n; i++) {
            maxSum = max(maxSum, prefsum[i] - minPrefix);
            minPrefix = min(minPrefix, prefsum[i]);
        }
        
        return maxSum;
    }
};