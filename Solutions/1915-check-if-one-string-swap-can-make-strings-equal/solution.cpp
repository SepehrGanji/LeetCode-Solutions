class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char ch1, ch2;
        bool done = false;
        bool redflag = false;
        for(int i = 0 ; i < s1.size() ; i++) {
            char a = s1[i], b = s2[i];
            if(a != b) {
                if(redflag) return false;
                if(!done) {
                    done = true;
                    ch1 = a;
                    ch2 = b;
                } else {
                    redflag = true;
                    done = false;
                    if(ch1 != b || ch2 != a) {
                        return false;
                    }
                }
            }
        }
        return !done;
    }
};
