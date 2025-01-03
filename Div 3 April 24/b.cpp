#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define el '\n'
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        if (count(a.begin(), a.end(), '0') == 0 || count(b.begin(), b.end(), '0') == 0 || count(a.begin(), a.end(), '1') == 0 || count(b.begin(), b.end(), '0') == 0) {
            cout << 0 << el;
            continue;
        }
        
        ll l = 0, r = 0, cnt = 0;
        while (r < min(n, m)) {
            if (a[r] == b[r]) {
                cnt++;
            }
        }
    }
    return 0;
}