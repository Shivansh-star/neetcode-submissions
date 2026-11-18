class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();
            if(one != two)pq.push(abs(one-two));
        }
        if(pq.size() == 0)return 0;
        return pq.top();
    }
};
