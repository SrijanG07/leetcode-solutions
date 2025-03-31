class BIT {
public:
    vector<long> arr;

    BIT(int n) {
        arr.resize(n + 1, 0);
    }

    void update(int idx, long val) {
        for (int i = idx; i < arr.size(); i += (i & -i)) {
            arr[i] += val;
        }
    }

    long get(int idx) {
        long result = 0;
        for (int i = idx; i > 0; i -= (i & -i)) {
            result += arr[i];
        }
        return result;
    }

    long query(int a, int b) {
        return get(b) - get(a - 1);
    }
};

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        BIT bit(n);
        long long result = 0;

        for (int j = 0; j < n; ++j) {
            long long running = 0;
            int val = nums[j];

            for (int k = j + 1; k < n; ++k) {
                if (nums[k] == nums[j]) continue;
                else if (nums[k] > nums[j]) {
                    result += running;
                } else {
                    running += bit.get(nums[k] - 1);
                }
            }

            bit.update(val, 1);
        }

        return result;
    }
};
