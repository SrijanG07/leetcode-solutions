class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        queue<int> q;
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++)
            q.push(i);
        int i=0;        
        vector<int> res(n);
        while(!q.empty()){
            int t=q.front();
            res[t]=deck[i++];
            q.pop();
            int x=q.front();
            q.pop();
            q.push(x);
        }
        return res;
    }
};