class Solution {
public:
    bool recurs(string& ree, int left, int right) {
        if (left > right) {
            return true;
        }
        if (ree[left] != ree[right]) {
            return false;
        }
        return recurs( ree, ++left , --right);
    }
    // space o[n] 
    bool isPalindrome(string s) {
        string ref;
        for (int i = 0; i<s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ref+=s[i];
            }
            if ((s[i] >= 'A') && ( s[i] <= 'Z')) {
                ref+= s[i] + 32;
            }
            if (s[i] >= '0' && s[i] <= '9'){
                ref+= s[i];
            }
        }
        int n = 0;
        int e = ref.length() -1;
        return recurs(ref,n,e);
    }
};