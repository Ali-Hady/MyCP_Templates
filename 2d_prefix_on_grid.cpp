//
// Created by ali on 12/17/2024.
//
#include <cctype>
#include <climits>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
#include <set>
#include<cmath>
#include <cstring>
#include <numeric>
#include <tuple>
#include <queue>
#include <stack>
#include <fstream>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int MOD = 1e9 + 7;
const ll inf = 2e18 + 1;
const int N = 1e6 + 3;

int main() {
    Ali;
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        ll pref[n+1][n+1] {}, prefxr[n+1][n+1] {}, prefxc[n+1][n+1] {}, a[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                pref[i][j] = a[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]; // 2d pref
                prefxr[i][j] = a[i - 1][j - 1] * (i - 1) + prefxr[i - 1][j] + prefxr[i][j - 1] - prefxr[i - 1][j - 1];
                prefxc[i][j] = a[i - 1][j - 1] * (j - 1) + prefxc[i - 1][j] + prefxc[i][j - 1] - prefxc[i - 1][j - 1];
            }
        }

        while (q--) {
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            // x * w + y + 1 -> zero based
            --x1, --y1;
            ll w = y2 - y1;
            ll sum = pref[x2][y2] - pref[x2][y1] - pref[x1][y2] + pref[x1][y1];
            ll sum_r = prefxr[x2][y2] - prefxr[x2][y1] - prefxr[x1][y2] + prefxr[x1][y1];
            ll sum_c = prefxc[x2][y2] - prefxc[x2][y1] - prefxc[x1][y2] + prefxc[x1][y1];

            cout << sum_r * w + sum_c + sum * (-x1 * w - y1 + 1) << " \n"[q == 0];
        }
    }

    return 0;
}