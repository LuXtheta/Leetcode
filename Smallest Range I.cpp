class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minn=1e9,maxx=-1e9;
        for(auto x : nums){
            minn = min(minn,x);
            maxx = max(maxx,x);
        }
        if(maxx-k-(minn+k)<=0){
            return 0;
        }
        return maxx-k-(minn+k);
    }
};