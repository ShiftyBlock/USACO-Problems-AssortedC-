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
        v<int> arr1(N);
        v<int> arr2(N);
        for(int i=0; i<N; i++){
            char c; cin>>c;
            arr1[i] = c-'0';
        }
        for(int i=0; i<N; i++){
            char c; cin>>c;
            arr2[i] = c-'0';
        }
        int ans = 0;
        for(int i=N-1; i>=0; i--){
            if(arr1[i] == 0){
                if(arr2[i]==1) ans++;
                arr2[i]  = 0;
            }
        }
        for(int i=0; i<N; i++){
            if(arr2[i]==1){
                if(i>0 && arr1[i-1]==1){
                    ans++;
                    arr1[i-1] = 0;
                }
                else if (i<N-1 && arr1[i+1]==1){
                    ans++;
                    arr1[i+1] = 0;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

