#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, k;
    cin >> n >> t >> k;

    vector<int> a;
    a.assign(t, 0);
    vector<int> number;
    number.assign(t, 0);
    int x = 2;
    int inevitable = 0;
    for (int i = 0; i < t; i++) {
        cin >> a[i];
        number[i] = x;
        x += a[i];
        if (i > 0 && a[i] < a[i-1]) {
            inevitable += a[i-1] - a[i];
        }
    }

    int minimum = a[t-1];
    int maximum = a[t-1];
    for (int i = t-2; i >= 0; i--) {
        minimum += a[i] - min(a[i], a[i+1]);
        maximum += a[i] - 1;
    }

    if (minimum > k || k > maximum) {
        cout << "-1\n";
        return 0;
    }

    // cout << minimum << ' ' << maximum << endl;
    // cout << inevitable << endl;
    k -= a[t-1];
    k -= inevitable;
    // cout << k << endl;
    cout << n << endl;
    for (int i = t-2; i >= 0; i--) {
        int next = number[i + 1];
        int next_limit = next + a[i + 1];
        int skip = a[i] > a[i+1] ? a[i]-a[i+1] : 0;
        for (int j = number[i]; j < number[i] + a[i] - 1; j++) {
            if (skip) {
                skip--;
                continue;
            }
            if (k > 0) {
                k--;
            } else if (next < next_limit) {
                cout << j << ' ' << next << endl;
                next++;
            }
        }
        while (next < next_limit) {
            cout << number[i] + a[i] - 1 << ' ' << next << endl;
            next++;
        }
    }
    for (int i = 0; i < a[0]; i++) {
        cout << 1 << ' ' << i+2 << endl;
    }

    return 0;
}