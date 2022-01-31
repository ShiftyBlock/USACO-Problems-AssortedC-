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
#define MAXVAL 100
long MOD = 1e9+7;
/*
 *
 */
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
    LOOP: while(tcs-->0){
        int N; cin>>N;
        v<int> a, b;
        for(int i=0; i<N; i++){
            int x; cin>>x; a.push_back(x);
        }
        for(int i=0; i<N; i++){
            int x; cin>>x; b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int asum = 0;
        int bsum=0;
        for(int i=N-1; i>=N/4; i--){
            asum+=a[i];
        }
        for(int i=N-1; i>=N/4; i--){
            bsum+=b[i];
        }
        if(asum>=bsum){
            cout<<0<<endl;
            continue;
        }
        int ans =0;
        int idx = N/4;
        int ct = N;
        for(int i=N/4-1; i>=0; i--){
            ct++;
            ans++;
            if(ct%4==0){
                asum+=MAXVAL;
                if(idx<N){
                    asum-=a[idx];
                    idx++;
                }
                i++;
                continue;
            }
            asum+=MAXVAL;
            bsum+=b[i];
            if(asum>=bsum) {
                cout<<ans<<endl;
                goto LOOP;
            }
        }
        while(idx<N || asum<bsum){
            asum+=MAXVAL;
            ct++;
            ans++;
            if(idx<N && ct%4==0){
                asum-=a[idx];
                idx++;
            }
            if(asum>=bsum) {
                cout<<ans<<endl;
                goto LOOP;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

