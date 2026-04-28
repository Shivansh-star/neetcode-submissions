class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        vector<vector<bool>> t(n, vector<bool>(n,false));

        for(int len = 1; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;

                if(i == j){
                    t[i][j] = true;
                }
                else if(i + 1 == j){
                    t[i][j] = (s[i] == s[j]);
                }
                else{
                    t[i][j] = (t[i+1][j-1] && s[i] == s[j]);
                }

                if(t[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};