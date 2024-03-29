/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define long long long
#define v vector

void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

}

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0) {
        long A, B;
        cin >> A >> B;
        if (B == 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;

        cout << A << " " << A * B << " " << A * B + A;
        cout << endl;
    }
    return 0;
}

