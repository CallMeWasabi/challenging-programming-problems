#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, k;
vector<int> spos, tpos;

bool can(ll r) {
    ll cnt = 0 ;
    ll cover = 0;
    ll idx = 0;

    for (int i=0; i<spos.size(); i++) {
        int x = spos[i];
        if (x <= cover) continue;

        int pi = -1;
        while (idx < tpos.size()) {
            int _pi = tpos[idx];
            if (_pi < x - r) idx++;
            else if (x - r <= _pi && _pi <= x + r) pi = _pi, idx++;
            else if (_pi > x + r) break;
        }

        if (pi == -1) return false;
        if (++cnt > k) return false;

        cover = pi + r;
    }

    return true;
}

void solve() {
    cin >> n >> k;
    spos.reserve(n);
    tpos.reserve(n);

    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        if (c == '1') spos.push_back(i);
    }
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        if (c == '1') tpos.push_back(i);
    }

    if (spos.empty() && k == 0) {
        cout << 0 << '\n';
        return;
    }
    if (tpos.empty() || k == 0) {
        cout << -1 << '\n';
        return;
    }

    ll l = 0, r = 1e6 + 7;
    while (l < r) {
        ll m = (l + r) / 2;

        if (can(m)) r = m;
        else l = m+1;
    }

    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();

    return 0;
}
