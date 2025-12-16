class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> hm;
        for (int i = 0; i< n ; i++) {
            hm[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int k = target - nums[i];
            if(hm.count(k) && hm[k] !=i) {
                ans.push_back(i);
                ans.push_back(hm[k]);
                break;
            }
        }
        return ans;
    }
};