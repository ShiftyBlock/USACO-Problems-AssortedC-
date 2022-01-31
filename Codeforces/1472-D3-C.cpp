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
        v<int> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        v<long> ans(N);
        for(int i=N-1; i>=0; i--){
            long j=i;
            long temp =0;
            while(j<N){
                if(j+arr[j] <N){
                    temp+=ans[j+arr[j]];
                    temp+=arr[j];
                    break;
                }
                temp+=arr[j];
                j+=arr[j];
            }
            ans[i] = temp;
        }
        long best =0;
        for(int i=0; i<N; i++){
            best = max(best, ans[i]);
        }
        cout<<best<<endl;
    }
    return 0;
}

