class BIT {
public:
    vector<int> ans;

    BIT(int size) {
        ans.resize(size + 1, 0);
    }

    void update(int i, int val) {
        while (i < ans.size()) {
            ans[i] += val;
            i += (i & -i);
        }
    }

    int query(int i) {
        int total = 0;
        while (i > 0) {
            total += ans[i];
            i -= (i & -i);
        }
        return total;
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int maxRating = *max_element(rating.begin(), rating.end());
        int count = 0;

        BIT left(maxRating), right(maxRating);

        for (int r : rating) {
            right.update(r, 1);
        }

        for (int cur_rating : rating) {
            right.update(cur_rating, -1);

            int smallerRatingsLeft = left.query(cur_rating - 1);
            int smallerRatingsRight = right.query(cur_rating - 1);
            int largerRatingsLeft = left.query(maxRating) - left.query(cur_rating);
            int largerRatingsRight = right.query(maxRating) - right.query(cur_rating);

            count += smallerRatingsLeft * largerRatingsRight;
            count += largerRatingsLeft * smallerRatingsRight;

            left.update(cur_rating, 1);
        }

        return count;
    }
};
