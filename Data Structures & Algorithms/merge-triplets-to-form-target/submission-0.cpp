
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool X = false;
        bool Y = false;
        bool Z = false;

        for(auto &t : triplets) {
            int x = t[0];
            int y = t[1];
            int z = t[2];

            if(x > target[0] || y > target[1] || z > target[2]) 
                continue;

            if(x == target[0]) X = true;
            if(y == target[1]) Y = true;
            if(z == target[2]) Z = true;
        }

        return X && Y && Z;
    }
};
