class SegmentTree
{
public:
	vector<int> seg;
	int len;
	SegmentTree(vector<int> &vec)
	{
		len = vec.size();
		seg.resize(4*len);
		build(vec, 0, len-1, 1);
	}

	void build(vector<int> &vec, int left, int right, int idx)
	{
		if(left == right)
		{
			seg[idx] = vec[left];
			return;
		}

		int mid = left + (right - left)/2;

		build(vec,left,mid,2*idx);
		build(vec,mid+1,right,2*idx+1);

		seg[idx] = max(seg[2*idx], seg[2*idx+1]);
	}

	long long int query(int li, int ri)
	{
		return queryHelper(li,ri,0,len-1,1);
	}
	// left = 0, right = len-1, segIndex = 1
	long long int queryHelper(int li, int ri, int left, int right, int segIndex)
	{
		int mid = left + (right - left)/2;
		if(right < li or left > ri) return 0;
		if(left >= li && right <= ri)
		{
			return seg[segIndex];
		}
		return max(queryHelper(li,ri,left,mid,2*segIndex), queryHelper(li,ri,mid+1,right,2*segIndex+1));
	}
};


class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        SegmentTree st(heights);
        vector<int> res;
        
        for(auto& q : queries) {
            int curr = heights.size();
            int end = heights.size()-1;
            int start = max(q[1],q[0]);
            int ans = heights.size();
            
            while(start <= end) {
                int mid = (start + end)/2;
                int one = st.query(start,mid);
                int two = st.query(mid,end);
                if(one > heights[q[0]] && one > heights[q[1]]) {
                    ans = mid;
                    end = mid-1;
                    continue;
                }
                if(two > heights[q[0]] && two > heights[q[1]]) {
                    ans = end;
                    start = mid+1;
                    continue;
                }
                break;
            }
            
            if(heights[max(q[0],q[1])] > heights[min(q[0],q[1])])
                ans = max(q[0],q[1]);
            if(q[0] == q[1]) 
                ans = q[0];
            if(ans == heights.size()) ans = -1;
            res.push_back(ans);
        }
        
        return res;
    }
};