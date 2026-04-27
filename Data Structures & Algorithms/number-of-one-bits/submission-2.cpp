class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n>0){
            int v = n%2;
            if(v == 1){
                cnt++;
            }
            n = n/2;
        }
        return cnt;
    }
};
