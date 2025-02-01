#include <iostream>
#include <numeric>
#include <set>

using namespace std;

typedef long long ll;

ll how_many_digits(ll n) {
    ll ret = 0;
    do {
        n /= 10;
        ret++;
    } while (n);
    return ret;
}

ll next_ten(ll n) {
    ll num_digits = how_many_digits(n);
    ll next_ten = 1;
    for (int i = 0; i < num_digits; i++) {
        next_ten *= 10;
    }
    return next_ten;
}

ll remaining_in_ndigit(ll n) {
    return next_ten(n) - n;
}

int main() {
    ll w, m, k;
    cin >> w >> m >> k;
    ll ans = 0;
    while (true) {
        ll digit = how_many_digits(m);
        ll rem = remaining_in_ndigit(m);
        ll cost = digit * k;
        ll possible = w / cost;
        if (possible >= rem) {
            ans += rem;
            w -= rem * digit * k;
            m = next_ten(m);
        } else {
            ans += possible;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}