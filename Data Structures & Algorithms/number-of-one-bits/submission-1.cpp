class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        int cnt = 0;
        while(n>0){
            int val = n % 2;
            if(val == 1){
                cnt++;
            }
            n = n / 2;
        }
        return cnt;
    }
};
