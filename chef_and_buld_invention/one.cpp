#include <iostream>

using namespace std;

int with_reminder_r(int N, int k, int r) {
    int n = N - 1;
    int ans = n/k;
    if (n%k >= r) {
        ++ans;
    }
    return ans;
}

int tc(int N, int k, int p) {
    int n = N - 1;
    int m = p % k - 1;
    int l = n % k;

    int ans = 1;
    ans += (m + 1) * (n / k);
    ans += min(l, m);

    ans += with_reminder_r(p + 1, k, p % k);

    return ans;
}

int main() {
    int t, N, p, k, ans;
    cin >> t;
    for (int i; i < t; i++) {
        cin >> N >> p >> k;
        ans = tc(N, k, p);
        cout << ans << endl;
    }
}