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
        v<long> arr;
        long ans = 0;

        for(int i=0; i<N; i++){
            long num; cin>>num; arr.push_back(num);
            if(i==0) ans+=num;
            if(i==N-1) ans+=num;
            if(i!=0) ans+=abs(arr[i] -arr[i-1] );
        }
        if(arr.size()==1){
            cout<<ans/2<<endl;
            continue;
        }
        for(int i=0; i<N; i++){
            if(i==0){
                if(arr[i] > arr[i+1]){
                    ans-= (arr[i] - arr[i+1]);
                   // arr[i] = arr[i+1];
                }
            }
            else if(i==N-1){
                if(arr[i] > arr[i-1]){
                    ans-= (arr[i] - arr[i-1]);
                }
            }
            else{
                if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                    ans-= min(arr[i] - arr[i - 1], arr[i] - arr[i + 1]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

