#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> tr;

void update(int i, int v, int l, int r, int idx=1) {
    if (r - l == 1) {
        tr[idx] = v;
        return;
    }
    int m = (l + r) /2;
    if (i < m) update(i, v, l, m, idx * 2);
    else update(i, v, m, r, idx * 2 + 1);
    tr[idx] = tr[idx * 2] + tr[idx * 2 + 1];
}

int kth(int k, int l, int r, int idx=1) {
    if (r - l == 1) return l;
    int m = (l + r) / 2;
    if (tr[idx * 2] >= k) return kth(k, l, m, idx * 2);
    return kth(k - tr[idx * 2], m, r, idx * 2 + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int k, s;
    cin >> k >> s;
    tr.resize(k * 4);

    int s_idx = -1;
    for (int i=0; i<k; i++) update(i, 1, 0, k);

    for (int i=0; i<k; i++) {
        int pi;
        cin >> pi;
        int idx = kth(pi, 0, k);
        if (idx + 1 == s) s_idx = i+1;
        cout << idx+1 << '\n';
        update(idx, 0, 0, k);
    }

    cout << s << " entered the restaurant on round " << s_idx;

    return 0;
}
