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
        int N, K; cin>>N>>K;
        v<int> arr;
        for(int i=0; i<N; i++){
            int n;cin>>n;
            arr.push_back(n);
        }
        int i=0;
        while(i<N && K!=0){
            if(arr[i]==0){
                i++;
                continue;
            }
            arr[i]--;
            arr[N-1]++;
            K--;
        }
        for(int i=0; i<N; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

