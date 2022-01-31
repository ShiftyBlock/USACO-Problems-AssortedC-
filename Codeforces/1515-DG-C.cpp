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
        int N,M,X;cin>>N>>M>>X;
        v<pii> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.emplace_back(num, i);
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        v<int> operations(N);
        cout<<"YES"<<endl;
        int j=0;
        for(int i=0; i<N; i++){
            operations[arr[i].second] = j;
            j++;
            j%=M;
        }
        for(int i=0; i<N; i++){
            cout<<operations[i]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

