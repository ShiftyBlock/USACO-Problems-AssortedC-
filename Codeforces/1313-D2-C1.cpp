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
    v<int> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
    }
    long best = 0;
    v<int> ans(N);
    for(int i=0; i<N; i++){
        long sum = 0;
        int cm = arr[i];
        for(int j=i;  j>=0; j--){
            sum+=min(cm, arr[j]);
            cm= min(cm, arr[j]);
        }
        if(i<N-1){
            cm = arr[i+1];
            for(int j=i+1; j<N; j++){
                sum+=min(cm, arr[j]);
                cm = min(cm, arr[j]);
            }
        }
        best= max(best, sum);
    }
    for(int i=0; i<N; i++){
        long sum = 0;
        int cm = arr[i];
        for(int j=i; j>=0; j--){
            sum+=min(cm, arr[j]);
            cm= min(cm, arr[j]);
        }
        if(i<N-1){
            cm = arr[i+1];
            for(int j=i+1; j<N; j++){
                sum+=min(cm, arr[j]);
                cm = min(cm, arr[j]);
            }
        }
        if(sum==best){
            cm = arr[i];
            for(int j=i; j>=0; j--){
                ans[j] = min(cm, arr[j]);
                cm= min(cm, arr[j]);
            }
            if(i<N-1){
                cm = arr[i+1];
                for(int j=i+1; j<N; j++){
                    ans[j] = min(cm, arr[j]);
                    cm = min(cm, arr[j]);
                }
            }
            break;
        }
    }
    for(int i=0; i<N; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

