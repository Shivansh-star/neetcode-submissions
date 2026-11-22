
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, l = n-1;

        while(s <= l) {
            int mid = s + (l-s)/2;

            if(nums[mid] == target)
                return mid;

            // Left half sorted
            if(nums[s] <= nums[mid]) {

                if(target >= nums[s] && target < nums[mid]) {
                    l = mid-1;
                } 
                else {
                    s = mid+1;
                }
            }

            // Right half sorted
            else {

                if(target > nums[mid] && target <= nums[l]) {
                    s = mid+1;
                } 
                else {
                    l = mid-1;
                }
            }
        }

        return -1;
    }
};
