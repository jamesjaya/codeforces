#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    v.assign(2 * n, 0);
    vector<vector<int>> pos;
    pos.assign(100, {});
    for (int i = 0; i < 2 * n; i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }

    int ret = 0;
    vector<int> ans;
    ans.assign(2 * n, 0);
    for (int i = 10; i <= 99; i++) {
        if (pos[i].size() > 1) {
            int odd = pos[i].size() % 2;
            int cur = 1;
            for (int j = odd; j < pos[i].size(); j++) {
                ans[pos[i][j]] = cur;
                cur = 3 - cur;
            }
        }
    }
    int cur = 1;
    for (int i = 10; i <= 99; i++) {
        if (pos[i].size() == 1) {
            ans[pos[i][0]] = cur;
            cur = 3 - cur;
        }
    }

    for (int i = 10; i <= 99; i++) {
        if (pos[i].size() > 1 && pos[i].size() % 2) {
            ans[pos[i][0]] = cur;
            cur = 3 - cur;
        }
    }
    
    unordered_set<int> cnt;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (ans[i] == 2 && ans[i] != ans[j]) {
                cnt.insert(v[i] * 100 + v[j]);
            }
        }
    }

    cout << cnt.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << endl;
    return 0;
}