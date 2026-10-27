class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(mp.find(target-val) != mp.end() && mp[target-val] != i){
                return {i,mp[target-val]};
            }
        }
        return {};
    }
};
