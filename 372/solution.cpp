int superPow(int a, vector<int>& b) {
    const int mod = 1337;
    int ret = 1;
    for (int i : b)  ret = power(ret, 10, mod) * power(a, i, mod) % mod;
    return ret;
}
int power(int x, int n, int mod) {
    x %= mod;
    int ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}