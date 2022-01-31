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
#define MOD (long) 1e9 +7
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
long res[10][200001];
void init(){
    for(int N=0; N<=9; N++) {
        deque<long> dp;
        v<int> arr(10);
        arr[N]++;
        for (int i = 0; i < 10; i++) {
            dp.emplace_back(arr[i]);
        }
        long ans = 1;
        res[N][0] = 1;
        for (int i = 1; i <= 200000; i++) {
            long last = dp.back();
            dp.pop_back();
            long first = dp.front();
            dp.pop_front();
            first += last;
            first%=MOD;
            last%=MOD;
            dp.push_front(first);
            dp.push_front(last);
            ans+=last;
            ans%=MOD;
            res[N][i]=ans;
        }
    }
}
int main() {
    setIO("", 0);
    init();
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, K; cin>>N>>K;
        deque<long> dp;
        int temp = N;
        v<int> arr(10);
        long ans =0;
        while(temp!=0){
            ans+=res[temp%10][K];
            ans%=MOD;
            temp/=10;
        }
        ans%=MOD;
        cout<<ans<<endl;
    }
    return 0;
}

