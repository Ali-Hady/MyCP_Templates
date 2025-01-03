//
// Created by ali on 1/3/2025.
//
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define el '\n'
using namespace std;

struct custom {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        if (p1.first > p2.first) {
            return true;
        }
        if (p1.first < p2.first) {
            return false;
        }
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1, cnt = 0;
    cin >> tc;
    while (tc--) {
        ++cnt;
        cout << "World #" << cnt << el;
        int n, m;
        cin >> n >> m;
        char grid[n][m];
        int frq[26] {};
        bool vis[n][m] {};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        int dx[] = {0, 0, +1, -1};
        int dy[] = {+1, -1, 0, 0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        auto &[x, y] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; ++k) {
                            int gox = x + dx[k];
                            int goy = y + dy[k];

                            if (gox < n && goy < m && gox >= 0 && goy >= 0 && !vis[gox][goy] && grid[gox][goy] == grid[x][y]) {
                                vis[gox][goy] = 1;
                                q.push({gox, goy});
                            }
                        }
                    }

                    frq[grid[i][j] - 'a']++;
                }
            }
        }

        set<pair<int, char>, custom> s;
        for (int i = 0; i < 26; ++i) {
            if (frq[i])
                s.insert({frq[i], 'a' + i});
        }

        for (auto &ansraya: s) {
            cout << ansraya.second << ": " << ansraya.first << el;
        }
    }

    return 0;
}
