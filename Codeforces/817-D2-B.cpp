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
    v<long> arr;
    map<long, long> m;
    for(int i=0; i<N; i++){
        long num; cin>>num; arr.push_back(num);
        m[num]++;
    }
    sort(arr.begin(), arr.end());
    int m1 = arr[0];
    int m2 = arr[1];
    int m3 = arr[2];
    if(m1==m2 && m2==m3){
        long ans = 1;
        for(int i=m[m1] - 2; i<=m[m1]; i++){
            ans*=i;
        }
        ans/=6;
        cout<<ans<<endl;
    }
    if(m1 == m2 && m2!=m3){
        cout<<m[m3]<<endl;
    }
    if(m1!=m2 && m2==m3){
        // m2 choose 2
        long ans = 1;
        for(int i=m[m2] - 1; i<=m[m2]; i++){
            ans*=i;
        }
        ans/=2;
        cout<<ans<<endl;
    }
    if(m1!=m2 && m2!=m3){
        cout<<m[m3]<<endl;
    }
    return 0;
}

