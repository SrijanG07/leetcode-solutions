class Solution {
public:

    bool check(vector<int>& nums) {
        int i = 0; 
        while(i<nums.size()-1) {
            if(nums[i] > nums[i+1]) {
                break;
            }
            i++;
        }
        if(i==nums.size()-1){
            return true;
        }
        else {
            while(i<nums.size()-1) {
                i++;
                if ( i == nums.size() - 1) {
                    if (nums[i] > nums[0]) {
                        return false;
                    }
                    return true;
                }
                if(nums[i] > nums[0] || nums[i] > nums[i+1]) {
                    return false;
                }
            }
            return true;
        }
    }
};