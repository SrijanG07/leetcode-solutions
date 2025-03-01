class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<int> q;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                q.push(matrix[r][c]);
                if(q.size()>k)q.pop();
            }
        }
        return q.top();
    }
};
