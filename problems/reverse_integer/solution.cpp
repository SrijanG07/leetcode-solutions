
class Solution {
public:
    int reverse(int x) {
        if (x <= INT_MIN) {
            return 0;
        }
        else if (x < 0) {
            string n = to_string(-1*x);
            std::reverse(n.begin(), n.end());
            if ( -1*stoll(n) > INT_MAX || -1*stoll(n) < INT_MIN ) {
                return 0;
            }
            else {
                cout << "-" + n << endl;
                return -1*stoi(n);
            }
        }
        else {
            string n = to_string(x);
            std::reverse(n.begin(), n.end());
            if ( stoll(n) > INT_MAX || stoll(n) < INT_MIN ) {
                return 0;
            }
            else {
                return stoi(n);
            }
        }
        
    }
};