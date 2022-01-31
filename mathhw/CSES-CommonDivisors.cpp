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
    int N; cin>>N;
    v<int> arr(1000001);

    for(int i=0; i<N; i++){
        int num; cin>>num; arr[num]++;
    }
    int best = 0;
    for(int k=1000000; k>=1; k--){
        int count = 0;
        for(int i=k; i<=1000000; i+=k){
            count+=arr[i];
        }
        if(count>=2) {
            best = k; break;
        }
    }
    cout<<best<<endl;

    return 0;
}
