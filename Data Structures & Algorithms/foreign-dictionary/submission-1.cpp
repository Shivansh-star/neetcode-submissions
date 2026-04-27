class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26,0);
        vector<int> present(26,0);

        string ans="";
        int n=words.size();

        for(auto &w: words){
            for(auto ch: w){
                present[ch-'a']=1;
            }
        }

        for(int i=0;i<n-1;i++){
            string word1=words[i];
            string word2=words[i+1];

            int k=0,p=0;

            while(k<word1.size() && p<word2.size()){
                if(word1[k]!=word2[p]){
                    bool found=false;

                    for(auto x: adj[word1[k]-'a']){
                        if(x==word2[p]-'a'){
                            found=true;
                            break;
                        }
                    }

                    if(!found){
                        adj[word1[k]-'a'].push_back(word2[p]-'a');
                        indegree[word2[p]-'a']++;
                    }
                    break;
                }
                else{
                    k++;
                    p++;
                }
            }

            if(p==word2.size() && k<word1.size()){
                return "";
            }
        }

        queue<int> q;

        for(int i=0;i<26;i++){
            if(present[i] && indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int i=q.front();
            q.pop();

            ans.push_back(i+'a');

            for(auto &it: adj[i]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<26;i++){
            if(present[i]) cnt++;
        }

        if(ans.size()!=cnt) return "";

        return ans;
    }
};