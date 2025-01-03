//
// Created by ali on 12/30/2024.
//
#include <cctype>
#include <iomanip>
#include <iostream>
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
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const ll inf = 2e18 + 1;
const int N = 2e5 + 3;

ll egcd(ll a, ll b, ll& x, ll& y, ll& cnt) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = egcd(b, a % b, x1, y1, ++cnt);
    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        ll a, b, x;
        cin >> a >> b >> x;
        if (x % gcd(a, b) != 0) {
            cout << -1 << el;
            continue;
        }

        //swap(a, b);
        ll g = gcd(a, b);
        ll mul = x / g;
        ll cnt = 0, f, y;
        egcd(a, b, f, y, cnt);
        if (f < 0)
            f += ((-f + (b / g - 1)) / (b / g)) * (b / g);
        cout << (f * mul) % (b / g) << el;
    }

    return 0;
}
