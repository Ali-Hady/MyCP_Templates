//
// Created by ali on 12/31/2024.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int p1 = 31; // A prime base for first hash
const int p2 = 53; // A prime base for second hash

// Modular arithmetic functions
ll add(ll x, ll y, ll mod) { return (x % mod + y % mod) % mod; }
ll mult(ll x, ll y, ll mod) { return (x % mod * y % mod) % mod; }

// Modular exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = mult(res, base, mod);
        base = mult(base, base, mod);
        exp >>= 1;
    }
    return res;
}

// Precompute powers of p and their modular inverses
vector<ll> power1, power2, inv_power1, inv_power2;

void precompute(int n) {
    power1.resize(n + 1), power2.resize(n + 1);
    inv_power1.resize(n + 1), inv_power2.resize(n + 1);

    power1[0] = power2[0] = 1;
    inv_power1[0] = inv_power2[0] = 1;

    ll inv_p1 = mod_exp(p1, MOD1 - 2, MOD1);
    ll inv_p2 = mod_exp(p2, MOD2 - 2, MOD2);

    for (int i = 1; i <= n; ++i) {
        power1[i] = mult(power1[i - 1], p1, MOD1);
        power2[i] = mult(power2[i - 1], p2, MOD2);
        inv_power1[i] = mult(inv_power1[i - 1], inv_p1, MOD1);
        inv_power2[i] = mult(inv_power2[i - 1], inv_p2, MOD2);
    }
}

// Compute hash values for all prefixes of the string
vector<pair<ll, ll>> compute_hash(const string &s) {
    int n = s.size();
    vector<pair<ll, ll>> hash(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i) {
        hash[i].first = add(hash[i - 1].first, mult(s[i - 1] - 'a' + 1, power1[i - 1], MOD1), MOD1);
        hash[i].second = add(hash[i - 1].second, mult(s[i - 1] - 'a' + 1, power2[i - 1], MOD2), MOD2);
    }
    return hash;
}

// Get hash of substring s[l:r] (1-based indexing)
pair<ll, ll> get_hash(int l, int r, const vector<pair<ll, ll>> &hash) {
    ll h1 = mult(add(hash[r].first, MOD1 - hash[l - 1].first, MOD1), inv_power1[l - 1], MOD1);
    ll h2 = mult(add(hash[r].second, MOD2 - hash[l - 1].second, MOD2), inv_power2[l - 1], MOD2);
    return {h1, h2};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();

    // Precompute powers and their inverses
    precompute(n);

    // Compute prefix hashes
    vector<pair<ll, ll>> hash = compute_hash(s);

    return 0;
}
