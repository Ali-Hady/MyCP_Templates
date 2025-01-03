#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
#define el '\n'
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    ll arr[n+1], dp[n+1];
    for (int i = 1; i <= n; i++) {
        dp[i] = (ll)1e18;
    }

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0; arr[0] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= min(i, k); j++) {
            dp[i] = min(dp[i - j] + abs(arr[i] - arr[i - j]), dp[i]);
        }
    }

    cout << dp[n] << el;
} 
