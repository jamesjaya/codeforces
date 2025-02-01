#include <iostream>
#include <numeric>
#include <set>

using namespace std;

pair<int, int> simplify(int num, int den) {
    if (den == 0) {
        return {1, 0};
    }

    if (num == 0) {
        return {0, 1};
    }

    int g = gcd(num, den);
    num /= g;
    den /= g;

    if (den < 0) {
        den = -den;
        num = -num;
    }

    return {num, den};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    set<pair<int, int>> cnt;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a -= x;
        b -= y;
        auto frac = simplify(b, a);
        cnt.insert(frac);
    }
    cout << cnt.size() << endl;
}