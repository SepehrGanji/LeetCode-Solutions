class Solution {
public:
bool isPrime(int n) {
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;
    if(n % 3 == 0) return false;
    for(int i = 5 ; i < sqrt(n) + 2 ; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
    int nonSpecialCount(int l, int r) {
        int start = floor(sqrt(l)) - 1;
    int es = 2;
    int ans = 0;
    while(es * es <= r) {
        //cout << "*" << es << endl;
        if(es * es >= l) ans++;
        es++;
        while(!(isPrime(es))) es++;
    }
    return r-l+1 - ans;
    }
};
