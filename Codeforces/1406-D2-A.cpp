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
        int N; cin>>N;
        v<int> frq(101);
        for(int i=0; i<N; i++){
            int n; cin>>n; frq[n]++;
        }
        int best = 0;
        int i=0;
        while(i<N){
            if(frq[i]>0) {
                frq[i]--;
            }
            else break;
            i++;
        }
        best+=i;
        i=0;
        while(i<N){
            if(frq[i]>0) {
                frq[i]--;
            }
            else break;
            i++;
        }
        best+=i;

        cout<<best<<endl;
    }
    return 0;
}

