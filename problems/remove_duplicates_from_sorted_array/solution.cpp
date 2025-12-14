#include<bits/stdc++.h>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> freq;
            for (int i = 0; i<nums.size(); i++) {
                freq[nums[i]]++;
            }
        int i = 0;
        for (auto x : freq) {
            nums[i++] = x.first;
        }
        return freq.size();
    }
};