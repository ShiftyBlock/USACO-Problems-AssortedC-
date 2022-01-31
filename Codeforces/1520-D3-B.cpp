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
int count_same_digit(int L, int R)
{
    long tmp = 0, ans = 0;

    // length of R
    int n = log10(R) + 1;

    for (int i = 0; i < n; i++) {

        // tmp has all digits as 1
        tmp = tmp * 10 + 1;

        // For each multiple
        // of tmp in range 1 to 9,
        // check if it present
        // in range [L, R]
        for (int j = 1; j <= 9; j++) {

            if (L <= (tmp * j)
                && (tmp * j) <= R) {

                // Increment th required count
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    setIO("", 0);
    int tcs=1;
    cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        cout<<count_same_digit(1, N)<<endl;
    }
    return 0;
}

