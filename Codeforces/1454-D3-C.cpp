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
            num--;
            arr.emplace_back(num);
        }
        v<int> ans(N);
        for(int i=1; i<N; i++){
            if(arr[i]!=arr[i-1]) ans[i] = 1;
        }
        v<bool> used(N);
        used[arr[N-1]] = true;
        for(int i=N-2; i>=0; i--){
            if(!used[arr[i]]) {
                if(arr[i] != arr[i+1]){
                    ans[i] ++;
                    used[arr[i]] = true;
                }
            }
        }
        v<int> freq(N);
        for(int i=0; i<N; i++){
            freq[i] = 1<<30;
        }
        for(int i=0; i<N; i++){
            freq[arr[i]] = 0;
        }
        for(int i=0; i<N; i++){
            freq[arr[i]]+=ans[i];
        }
        int m = 1<<30;
        for(int i=0; i<N; i++){
            m = min(m, freq[i]);
        }
        cout<<m<<endl;
    }
    return 0;
}

