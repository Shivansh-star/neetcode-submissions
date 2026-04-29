class Solution {
public:
    bool isAnagram(string s, string t) {

        int n1 = s.length();
        int n2 = t.length();

        if(n1 != n2) return false;

        unordered_map<char,int> mp;

        for(int i=0;i<n1;i++){
            mp[s[i]]++;
        }

        for(int i=0;i<n2;i++){
            mp[t[i]]--;

            if(mp[t[i]] < 0)
                return false;
        }

        for(auto &i : mp){
            if(i.second > 0)
                return false;
        }

        return true;
    }
};