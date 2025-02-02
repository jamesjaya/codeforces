#include <iostream>
#include <vector>
#include <format>

using namespace std;

typedef long long ll;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string fi = "What are you doing while sending \"{}\"? Are you busy? Will you send \"{}\"?";
ll len[56];

ll first_segment_length(ll n) {
    return n * 34;
}

char calc(ll n, ll k) {
    if (n == 0) {
        if (k <= f0.size()) {
            return f0[k-1];
        } else {
            return '.';
        }
    }
    
    ll first_segment = 34;
    if (k <= first_segment) {
        return fi[k-1];
    }

    if (n <= 55) {
        if (k > len[n]) {
            return '.';
        }
        ll second_segment = first_segment + len[n-1];
        if (k <= second_segment) {
            return calc(n-1, k-first_segment);
        }
        ll third_segment = second_segment + 32;
        if (k <= third_segment) {
            ll rem = k - second_segment + 36;
            return fi[rem-1];
        }
        ll fourth_segment = third_segment + len[n-1];
        if (k <= fourth_segment) {
            return calc(n-1, k-third_segment);
        }
        ll fifth_segment = fourth_segment + 2;
        if (k <= fifth_segment) {
            ll rem = k - fourth_segment + 70;
            return fi[rem-1];
        }
    } else {
        return calc(n-1, k-first_segment);
    }
    
    return '.';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    len[0] = f0.size();
    for (int i = 1; i <= 55; i++) {
        len[i] = 34ll + len[i-1] + 32ll + len[i-1] + 2ll;
    }

    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << calc(n, k);
    }
    cout << endl;
}