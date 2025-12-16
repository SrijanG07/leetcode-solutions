class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> hm;
        for(int i = 0; i<n ; i++) {
            hm[nums[i]]++;
        }
        for (int i = 0; i< 3; i++) {
            for (int j = 0; j< hm[i]; j++) {
                ans.push_back(i);
            }
        }
        nums = ans;
    }
};