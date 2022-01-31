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
    v<int> arr;
    arr.push_back(0);
    v<int> psum(N+1);
    long add = 0;
    long cur=0;
    for(int i=0; i<N; i++){
        int x; cin>>x;
        if(x==1){
            int a, b; cin>>a>>b;
            psum[a-1]+=b;
            add+=a*b;
        }
        if(x==2){
            int num; cin>>num;
            arr.push_back(num);
            cur+=num;
        }
        if(x==3){
            int idx = (int)arr.size()-1;
            psum[idx-1]+=psum[idx];
            add-= psum[idx];
            psum[idx] = 0;
            cur-= arr.back();
            arr.pop_back();
        }
        double ans = (0.0+add+cur)/arr.size();
        cout.precision(17);
        cout<<ans<<endl;
    }
    return 0;
}

