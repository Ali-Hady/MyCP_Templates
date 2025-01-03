//
// Created by ali on 1/3/2025.
//
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define el '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1, cnt = 0;
    cin >> tc;
    vector<int> spf(2e7+1, 0);
    spf[0] = spf[1] = 0;
    for (int i = 2; i <= 2e7; ++i) spf[i] = i;
    for (int i = 2; i * i <= 2e7; ++i) {
        if (spf[i] != i) continue;
        for (int j = i * i; j <= 2e7; j += i) {
            spf[j] = min(spf[j], i);
        }
    }

    vector<ll> pre(1e6+1);
    function<ll(ll)> nod = [&] (ll m) {
        ll ans = 1;
        int prv = -1, cnt = 0;
        while (m > 1) {
            int p = spf[m];
            if (p != prv) {
                prv = p;
                ans *= (cnt+1);
                cnt = 1;
            }
            else ++cnt;
            m /= p;
        }

        ans *= (cnt + 1);

        return ans;
    };

    pre[0] = 1;
    pre[1] = 2;
    for (int i = 2; i <= 1e6; ++i) {
        pre[i] = pre[i - 1] + nod(pre[i - 1]);
    }

    cnt = 0;
    while (tc--) {
        ++cnt;
        ll a, b;
        //for (int i = 0; i < 10; ++i) cout << pre[i] << ' ';
        cin >> a >> b;
        int l = lower_bound(pre.begin(), pre.end(), a) - pre.begin();
        int r = upper_bound(pre.begin(), pre.end(), b) - pre.begin();
        cout << "Case " << cnt << ": " << r - l << el;
    }

    return 0;
}
