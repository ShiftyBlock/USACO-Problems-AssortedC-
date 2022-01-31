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
        v<int> monsters;
        int bad=0;
        for(int i=0; i<N; i++){
            int num; cin>>num; monsters.push_back(num);
            bad= max(bad, num);
        }
        int M; cin>>M;
        v<pii> arr;
        v<int> best(N+1);
        for(int i=0; i<M; i++){
            int a,b; cin>>a>>b; arr.push_back(make_pair(a,b));
            best[b] = max(best[b], a);
        }
        for(int i=N-1; i>=0; i--){
            best[i] = max(best[i], best[i+1]);
        }
        if(best[0] < bad){
            cout<<-1<<endl;
            continue;
        }
        int day=0;
        for(int i=0; i<N;){
            int j=i;
            int high = 0;
            while(j<N){
                high = max(high, monsters[j]);
                if(best[j-i+1] < high){
                    break;
                }
                j++;
            }
            i=j;
            day++;
        }
        cout<<day<<endl;
    }
    return 0;
}

