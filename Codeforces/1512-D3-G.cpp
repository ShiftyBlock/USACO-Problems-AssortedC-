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
const int N = 10000001;
int sumdiv[N + 1];
int rev[N+1];
void calculate() {
    for (int i = 1; i <= N; ++i){
        for (int j = i; j <= N; j += i) {
            sumdiv[j] += i;
        }
    }
    for(int i=0; i<N; i++){
        if(sumdiv[i]<N && rev[sumdiv[i]] == 0){
            rev[sumdiv[i]] = i;
        }
    }
};


int main() {
    setIO("", 0);
    calculate();

    int c; cin>>c;
    while(c-->0){
        int a; cin>>a;
        if(rev[a]==0) cout<<-1<<endl;
        else cout<<rev[a]<<endl;
    }

    return 0;
}

