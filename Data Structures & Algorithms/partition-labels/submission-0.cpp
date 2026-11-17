class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        vector<int>ans;
        int n = s.length();
        for(int i=0;i<s.length();i++){
            mp[s[i]] = i;
        }
        int i=0;
        int cnt = 0;
        while(i<n){
            int cnt = 0;
            char val = s[i];
            int l = mp[s[i]];
            while(i<=l){
                cnt++;
                l = max(l,mp[s[i]]);
                i++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
