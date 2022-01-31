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
    v<pii> arr;
    for(int i=0; i<N; i++){
        long a, b; cin>>a>>b; arr.emplace_back(b,a);
    }
    sort(arr.begin(), arr.end());
    int i=0; int j=N-1;
    long K = 0;
    long cost = 0;
    while(i<N){
        if(0==arr[i].second) {
            i++; continue;
        }
        if(arr[i].first > K){
            while(j>=0){
                if(arr[j].second>arr[i].first - K ){
                    arr[j].second -= arr[i].first -K;
                    cost+=(arr[i].first- K)*2;
                    K=arr[i].first;
                    break;
                }
                else {
                    K+=arr[j].second;
                    cost+=arr[j].second *2;
                    arr[j].second =0;
                    j--;
                }
            }
        }
        cost+=arr[i].second;
        K+=arr[i].second;
        i++;
    }
    cout<<cost<<endl;
    return 0;
}

