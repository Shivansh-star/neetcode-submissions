class Solution {
public:
    bool check(unordered_map<char,int>& mp){
        for(auto &i : mp){
            if(i.second > 1) return false;
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        int ans = 0;
        int i = 0, j = 0;

        while(i < n){
            mp[s[i]]++;

            while(check(mp) == false){
                mp[s[j]]--;
                j++;
            }

            ans = max(ans, i-j+1);
            i++;
        }

        return ans;
    }
};