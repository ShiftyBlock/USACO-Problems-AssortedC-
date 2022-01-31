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
    int N; cin>>N;

    v<int> arr(N);
    int avoid = 1;
    while(avoid<=N){
        int ct = 0;
        for(int i=0; i<N; i++){
            if(arr[i]!=0) continue;
            ct++;
        }
        if(ct==3){
            for(int i=0; i<N; i++){
                if(arr[i]!=0) continue;
                if(ct==1) break;
                arr[i] = avoid;
                ct--;
            }
            for(int i=0; i<N; i++){
                if(arr[i]!=0) continue;
                arr[i] = i+1;
            }
        }
        else {
            for (int i = 0; i < N; i++) {
                if (arr[i] != 0) continue;
                int c = i + 1;
                if (c % (avoid * 2) == 0) continue;
                arr[i] = avoid;
            }
        }
        avoid*=2;
    }
    v<int> frq(1e6);
    for(int i=0; i<N; i++){
        frq[arr[i]]++;
    }
    for(int i=0; i<=N; i++){
        while(frq[i]>0){
            cout<<i<<" ";
            frq[i]--;
        }
    }
    cout<<endl;

    return 0;
}

