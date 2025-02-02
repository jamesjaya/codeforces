#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

ll rollhash(const string& s, int mod) {
    ll ret = 0;
    for (int i = 0; i < s.size(); i++) {
        int idx = (i + mod) % s.size();
        ret *= 29ll;
        ret += s[idx]-'a'+1ll;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<ll, int> mov;
    for (int i = 0; i < s.size(); i++) {
        ll rhash = rollhash(s, i);
        if (!mov.contains(rhash)) {
            mov[rollhash(s, i)] = i;
        }
    }
    for (int i = 1; i < n; i++) {
        cin >> s;
        unordered_set<ll> seen;
        for (int j = 0; j < s.size(); j++) {
            ll rhash = rollhash(s, j);
            if (!mov.contains(rhash)) {
                cout << "-1\n";
                return 0;
            }
            if (!seen.contains(rhash)) {
                mov[rhash] += j;
                seen.insert(rhash);
            }
        }
    }
    int ans = 1e9;
    for (const auto& d: mov) {
        ans = min(ans, d.second);
    }
    cout << ans << endl;
    return 0;
}