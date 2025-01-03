//
// Created by ali on 1/3/2025.
//
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#define ll long long
#define el '\n'
using namespace std;

int n, sz;
vector<vector<ll>> dp;
vector<ll> v;
ll solve(int idx, ll current_sum) {
    if (idx == sz) return current_sum;

    ll &ret = dp[idx][current_sum];
    if (~ret) return ret;

    ll op1 = solve(idx + 1, current_sum);

    ll op2 = (current_sum + v[idx] <= n) ? solve(idx + 1, current_sum + v[idx]) : current_sum;

    return ret = max(op1, op2);
}

void build(int idx, ll current_sum) {
    if (idx == sz) return;

    ll without_current = solve(idx + 1, current_sum);
    ll with_current = (current_sum + v[idx] <= n) ? solve(idx + 1, current_sum + v[idx]) : current_sum;

    if (with_current > without_current) {
        cout << v[idx] << ' ';
        build(idx + 1, current_sum + v[idx]);
    } else {
        build(idx + 1, current_sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //int tc = 1;
    //cin >> tc;
    while (cin >> n) {
        /*
        for (int i = 0; i <= sz; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = -1;
            }
        }*/

        //int sz;
        cin >> sz;
        dp.assign(sz + 1, vector<ll>(n + 1, -1));
        v.resize(sz);
        for (int i = 0; i < sz; ++i) {
            cin >> v[i];
        }

        ll sum = solve(0, 0);
        build(0, 0);
        cout << "sum:" << sum << el;
    }

    return 0;
}
