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
    int i=1;
    int j = 0;
    v<int> ans(N);
    while(i<N){
        int a,b;
        cout<<"? "<<j+1<<" "<<i+1<<endl;
        cout.flush();
        cin>>a;
        cout<<"? "<<i+1<<" "<<j+1<<endl;
        cout.flush();
        cin>>b;
        if(a>b){
           // max mod cur, if a>b means this is not max
           ans[j] = a;
           j=i;
        }
        if(b>a) {
            // cur mod max, if b>a means this is not max
            ans[i] = b;
        }
        i++;
    }
    ans[j]  =N;
    cout<<"! ";
    for(int num: ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}

