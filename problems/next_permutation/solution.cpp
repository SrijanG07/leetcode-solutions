class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int s = nums.size()-2; 
        int e = nums.size()-1;
        bool x = false;
        while(s>=0 && nums[s] >= nums[s+1]) {
            s--;
        }
        if(s>=0) {
            while (nums[s] >= nums[e]) {
                e--;
            }
            swap(nums[s],nums[e]);
        }
        sort(nums.begin()+s+1,nums.end());

    }
};