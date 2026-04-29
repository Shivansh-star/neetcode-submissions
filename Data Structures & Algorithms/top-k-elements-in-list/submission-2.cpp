class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto &i : nums){
            mp[i]++;
        }
        for(auto &i : mp){
            pq.push({i.second,i.first});
        }
        while(!pq.empty() && k != 0){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            k--;
        }
        
        return ans;
    }
};
