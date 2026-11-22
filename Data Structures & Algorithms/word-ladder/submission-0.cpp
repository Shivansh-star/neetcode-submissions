class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string>st;
        for(int i=0;i<n;i++)st.insert(wordList[i]);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto [s,cnt] = q.front();
            q.pop();
            if(s == endWord)return cnt;
            for(int i=0;i<s.length();i++){
                char temp = s[i];
                for(char k='a';k<='z';k++){
                    if(k == temp)continue;
                    s[i] = k;
                    if(st.find(s) != st.end()){
                        q.push({s,cnt+1});
                        st.erase(s);
                    }
                }
                s[i] = temp;
            }
        }
        return 0;
    }
};
