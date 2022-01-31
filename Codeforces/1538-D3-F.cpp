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

long MOD = 1e9+7;

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
    while(tcs-->0){
        int L,R; cin>>L>>R;
        long cL = 0;
        long add = 1;
        while(L!=0){
            cL+=L%10 * add;
            L/=10;
            add*=10; add++;
        }
        long cR = 0;
        add = 1;
        while(R!=0){
            cR+=R%10 * add;
            R/=10;
            add*=10; add++;
        }
        cout<<cR - cL<<endl;
    }
    // we need a way to process intersections at the same time
    // and to check for visited points at before times
    return 0;
}
int visited[1000000000][1000000000];
1e18 ints
// you get 1e8 operations per second
// and you get 256 megabytes
// and an integer is 4 bytes
// so you can put 64 million ints
// which is 6.4 e7
// but this thing is 1e18
