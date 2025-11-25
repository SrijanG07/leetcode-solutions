class Solution {
public:
    int isPalindrome(int x) {
        long long num = x;
        long long reverse = 0;
        while (x > 0) {
            reverse = (reverse * 10) + x%10;
            x = x/10;
        }
        return reverse == num ; 
    }
};