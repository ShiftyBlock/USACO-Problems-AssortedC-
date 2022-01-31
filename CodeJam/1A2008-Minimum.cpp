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
    int temp=tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> a;
        v<int> b;
        for(int i=0; i<N; i++){
            int num; cin>>num;
            a.push_back(num);
        }
        for(int i=0; i<N; i++){
            int num; cin>>num;
            b.push_back(num);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        long answer=0;
        for(int i=0; i<N; i++){
            answer+=(long) a[i] * b[i];
        }
        cout<<"Case #"<<temp-tcs<<": "<<answer<<endl;
    }
    return 0;
}

