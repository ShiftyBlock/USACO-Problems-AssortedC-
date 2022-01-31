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
            int num; cin>>num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        int ans =0;
        v<int> pos;
        for(int i=0; i<N; i++){
            if(arr[i]<=0)ans++;
            if(arr[i]>0) pos.push_back(arr[i]);
        }
        sort(pos.begin(), pos.end());
        if(pos.size()>0){
            int gap = pos[0];
            bool canadd = true;
            for(int i=1; i<N; i++){
                if(arr[i]<=0){
                    if(arr[i] - arr[i-1] < gap) canadd=false;
                }
            }
            if(canadd) ans++;
        }

        cout<<ans<<endl;

    }
    return 0;
}

