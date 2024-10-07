class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool doI = false;
        int last_idx = -1;
        for(int i = 0 ; i < bits.size(); i++) {
            int bit = bits[i];
            if(bit == 0) {
                // 0
                if(doI) {
                    doI = false;
                } else {
                    last_idx = i;
                }
            } else {
                // 1
                if(doI) {
                    doI = false;
                } else {
                    doI = true;
                }
            }
        }
        
        return last_idx == bits.size()-1;
    }
};
