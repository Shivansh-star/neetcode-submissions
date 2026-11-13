class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int start = newInterval[0];
        int end = newInterval[1];

        int n = intervals.size();
        int j = 0;

        for(int i = 0; i < n; i++) {

            if(intervals[i][1] < start) {
                ans.push_back(intervals[i]);
            }
            else {
                int st = min(intervals[i][0], start);
                j = i;

                int e = end;

                while(j < n && intervals[j][0] <= e) {
                    e = max(e, intervals[j][1]);
                    j++;
                }

                ans.push_back({st, e});

                i = j - 1;
                start = INT_MAX;
            }
        }

        if(start != INT_MAX) {
            ans.push_back({start, end});
        }

        return ans;
    }
};