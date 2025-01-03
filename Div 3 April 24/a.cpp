#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#define ll long long
#define el '\n'
#define Ali ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

int gcds[1000 + 1] {};

int main() {
    /*'.'*/ Ali; /*'.'*/
    ll t, x;
    for (int i = 2; i<= 1000; i++) {
        int maxi = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (gcd(i, j) + j > gcds[i]) {
                gcds[i] = j;
            }
        }
    }

    cin >> t;
    while (t--) {
        cin >> x;
        cout << x - 1 << el;
    }

    return 0;
}