class Solution {
public:
    bool valid(vector<int>& piles, int m, int h) {
        long long hars = 0;

        for(int i = 0; i < piles.size(); i++) {
            hars += piles[i] / m + (piles[i] % m != 0);
        }

        return hars <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(valid(piles, mid, h)) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }

        return ans;
    }
};