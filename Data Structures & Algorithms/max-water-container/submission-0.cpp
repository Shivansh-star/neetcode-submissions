class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxi = INT_MIN;
        while(l<=r){
            int w = (r-l);
            int h = min(height[l],height[r]);
            maxi = max(w*h,maxi);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxi;
    }
};