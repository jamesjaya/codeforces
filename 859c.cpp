#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_sum;

int mem_alice[50];
int mem_bob[50];

int bob(const vector<int>& pies, int idx);

int alice(const vector<int>& pies, int idx) {
    if (idx == pies.size()) {
        return 0;
    }
    if (mem_alice[idx] != -1) {
        return mem_alice[idx];
    }
    int skip = alice(pies, idx + 1);
    int take = pies[idx];
    if (idx + 1 < pies.size()) {
        take += prefix_sum[idx + 1] - bob(pies, idx + 1);
    }
    mem_alice[idx] = max(skip, take);
    return mem_alice[idx];
}

int bob(const vector<int>& pies, int idx) {
    if (idx == pies.size()) {
        return 0;
    }
    if (mem_bob[idx] != -1) {
        return mem_bob[idx];
    }
    int skip = bob(pies, idx + 1);
    int take = pies[idx];
    if (idx + 1 < pies.size()) {
        take += prefix_sum[idx + 1] - alice(pies, idx + 1);
    }
    mem_bob[idx] = max(skip, take);
    return mem_bob[idx];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 50; i++) {
        mem_alice[i] = -1;
        mem_bob[i] = -1;
    }

    int n;
    cin >> n;

    vector<int> pies;
    int sum = 0;
    pies.assign(n, 0);
    prefix_sum.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> pies[i];
    }
    for (int i = n-1; i >= 0; i--) {
        sum += pies[i];
        prefix_sum[i] = sum;
    }

    int bobx = bob(pies, 0);
    cout << sum - bobx << ' ' << bobx << '\n';
    return 0;
}