class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 0;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int st = intervals[i][0];
            int ed = intervals[i][1];
            int j=i;
            while(j<n && ed>=intervals[j][0]){
                ed = max(intervals[j][1],ed);
                j++;
            }
            ans.push_back({st,ed});
            i=j-1;
        }
        return ans;        
    }
};
