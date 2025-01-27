class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0 || right == 0) return 0;
        if(left == right) return left;
        int l = log2(left), r = log2(right);
        if(l != r) return 0;
        int i = 0;
        while(left != right) {
            left /= 2;
            right /= 2;
            i++;
        }
        while(i--) {
            left *= 2;
        }
        return left;
    }
};
