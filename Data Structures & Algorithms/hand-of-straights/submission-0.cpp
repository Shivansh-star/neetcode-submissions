class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;

        map<int,int> mp;

        for(int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }

        while(!mp.empty()) {

            int val = mp.begin()->first;

            int k = 1;

            while(k != groupSize) {

                if(mp.find(val + 1) != mp.end()) {
                    mp[val + 1]--;

                    if(mp[val + 1] == 0) {
                        mp.erase(val + 1);
                    }

                    k++;
                }
                else {
                    return false;
                }

                val++;
            }

            mp[val - groupSize + 1]--;

            if(mp[val - groupSize + 1] == 0) {
                mp.erase(val - groupSize + 1);
            }
        }

        return true;
    }
};