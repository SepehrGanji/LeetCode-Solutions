class Solution {
public:
    bool canCross(vector<int>& stones) {
        set<int> st;
        unordered_map<int, set<int>> mp;
        for(auto el: stones) st.insert(el);
        //
        mp[stones[0]].insert(0);
        for(int i = 0 ; i < stones.size() - 1 ; i++) {
            int current_stone_position = stones[i];
            auto myset = mp[current_stone_position];
            if(myset.empty()) continue;
            for(auto jm: myset) {
                int poss[] = {-1, 0, 1};
                for(int p = 0 ; p < 3 ; p++) {
                    int jump_length = jm+poss[p];
                    int new_stone = current_stone_position + jump_length;
                    if(st.find(new_stone) != st.end()) {
                        mp[new_stone].insert(jump_length);
                    }
                }
            }
        }
        if(mp[stones[stones.size()-1]].empty()) return false;
        return true;
    }
};
