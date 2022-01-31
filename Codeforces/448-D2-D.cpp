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
    long N, M, K; cin>>N>>M>>K;if(N*M==K) {
        cout<<N*M<<endl;
        return 0;
    }
    long low = 0;
    long high =1LL * 5e5 * 5e5 ;
    long best = 0;
    for(int i=0; i<N; i++){

    }
    while(low<high){
        long mid = (low+high)/2;
        long sum = 0;
        long include = 0;
        for(int i=1; i<=N; i++){
            sum+=min(M, (mid-1)/i);
            include+=min(M, (mid)/i);
        }
        if(sum<K) low = mid+1;
        else high =mid;
    }
    cout<<low-1<<endl;

    return 0;
}

