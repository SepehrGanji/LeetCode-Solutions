class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0 ; i < flowerbed.size() ; i++) {
            if(flowerbed[i] == 0) {
                bool lefty = true;
                bool righty = true;
                if(i > 0 && flowerbed[i-1] == 1) lefty = false;
                if(i < flowerbed.size()-1 && flowerbed[i+1] == 1) righty = false;
                if(lefty && righty) {
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        return n <= 0;
    }
};
