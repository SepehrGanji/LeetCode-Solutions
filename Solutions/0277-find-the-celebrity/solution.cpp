/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    bool isCel(int a, int n) {
        for(int i = 0 ; i < n ; i++) {
            if(i == a) continue;
            if(knows(i, a) == false) return false;
            if(knows(a, i) == true) return false;
        }
        return true;
    }

    int findCelebrity(int n) {
        for(int i = 0 ; i < n ; i++) {
            if(isCel(i, n)) return i;
        }
        return -1;
    }
};

