class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        int cnt = 0;
        for (int i = 0; i<n; i++) {
            if (nums[i] != 0) {
                nums[k] = nums[i];
                k++;
            }
            if (nums[i] == 0) {
                cnt++;
            }
        }
        while(k<n) {
            nums[k] = 0;
            k++;
        }

        
    }
};