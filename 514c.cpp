#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

struct node {
    bool end = false;
    node* next[3] = {NULL, NULL, NULL};
};

void insert(node* root, const string& val) {
    node* cur = root;
    for (char c: val) {
        int idx = c - 'a';
        if (!cur->next[idx]) {
            cur->next[idx] = new node();
        }
        cur = cur->next[idx];
    }
    cur->end = true;
}

bool query(node* cur, const string& val, int pos, bool diff) {
    // cout << pos << ' ' << diff;
    if (pos == val.size()) {
        return diff && cur->end ? true : false;
    }

    if (!diff) {
        for (int i = 0; i < 3; i++) {
            if (cur->next[i]) {
                auto ret = query(cur->next[i], val, pos+1, (val[pos] - 'a') != i);
                if (ret) {
                    return true;
                }
            }
        }
        return false;
    } else {
        while (pos < val.size()) {
            int idx = val[pos] - 'a';
            if (cur->next[idx]) {
                cur = cur->next[idx];
                pos++;
            } else {
                return false;
            }
        }
    }
    
    return diff && cur->end ? true : false; 
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    node nx;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(&nx, s);
    }

    while (m--) {
        string s;
        cin >> s;
        bool found = query(&nx, s, 0, false);
        cout << (found ? "YES" : "NO") << '\n';
    }
}