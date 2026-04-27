class Solution {
public:
    bool all_zero(unordered_map<char,int> mp){
        for(auto &i: mp){
            if(i.second>0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char,int> mp;

        for(char ch : t){
            mp[ch]++;
        }

        int j=0;
        int mini=INT_MAX;
        int start=0;

        for(int i=0;i<s.size();i++){

            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]--;
            }

            while(j<=i && all_zero(mp)){

                if(i-j+1 < mini){
                    mini=i-j+1;
                    start=j;
                }

                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]++;
                }

                j++;
            }
        }

        if(mini==INT_MAX) return "";

        return s.substr(start,mini);
    }
};