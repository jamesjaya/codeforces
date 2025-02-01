#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;

    for (int i = 0; i < k; ++i) {
        ll ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;

        ll tdiff = abs(tb - ta);
        if (tdiff == 0) {
            cout << abs(fa - fb) << '\n';
        } else {
            ll ans = 0;
            if (fa >= a && fa <= b) {
                ans += abs(fa - fb);
            } else {
                bool x = abs(fa - a) < abs(fa - b);
                ans += x ? abs(fa - a) : abs(fa - b);
                ans += x ? abs(fb - a) : abs(fb - b);
            }
            
            cout << tdiff + ans << '\n';
        }
    }
}