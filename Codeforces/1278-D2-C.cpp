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
        int sum = 0;
        for(int i=0; i<2*N; i++){
            int num; cin>>num;
            if(num==1){
                arr.push_back(1);
            }
            else arr.push_back(-1);
            sum+=arr[i];
        }
        v<int> prefix(N);
        for(int i=N-1; i>=0; i--){
            if(i==N-1) prefix[i] = arr[i];
            else prefix[i] = prefix[i+1] + arr[i];
        }
        v<int> suffix(2*N);
        for(int i=N; i<2*N; i++){
            if(i==N) suffix[i] = arr[i];
            else suffix[i] = suffix[i-1] + arr[i];
        }
        v<pii> pairs;
        for(int i=N; i<2*N; i++){
            pairs.emplace_back(suffix[i], i);
        }
        sort(pairs.begin(), pairs.end());
        if(sum==0){
            cout<<0<<endl;
            continue;
        }
        int best = 1<<30;
        for(int i=0; i<N; i++){
            int temp = sum;
            temp-= prefix[i];
            if(temp==0){
                best = min(best, N-i);
                continue;
            }
            auto x = lower_bound(pairs.begin(), pairs.end(), make_pair((long)temp, (long)-1));
            if(x==pairs.end() || (*x).first !=temp) continue;
            best = min(best, (N-i) + (int) (*x).second-N+1);
        }
        auto x = lower_bound(pairs.begin(), pairs.end(), make_pair((long) sum, (long) -1));
        if(x!=pairs.end() && (*x).first == sum) best = min(best, 1+ (int)((*x).second)-N);
        cout<<best<<endl;


    }
    return 0;
}

