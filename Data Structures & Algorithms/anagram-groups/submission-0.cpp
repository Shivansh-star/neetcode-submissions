class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        vector<pair<string,string>> v;

        for(auto &s : strs){
            string t=s;
            sort(t.begin(),t.end());
            v.push_back({t,s});
        }
        sort(v.begin(),v.end());
        int i=0;
        while(i<v.size()){
            vector<string> val;
            string cur=v[i].first;
            while(i<v.size() && v[i].first==cur){
                val.push_back(v[i].second);
                i++;
            }

            ans.push_back(val);
        }

        return ans;
    }
};