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
    while(tcs-->0 ){
        int N; cin>>N;
        v<int> arr;
        map<int, int> m;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
            m[num]++;
        }
        v<int> count(N+1);
        for(auto x: m){
            count[x.second]++;
        }
        long best = 1<<30;
        long ans =0;
        for(int i=N-1; i>=0; i--){
            ans+=count[i] * (i);
        }
        count[0]=1;
        best = ans;
        int i=N;
        int big=0;
        while(i>=0){
            if(count[i]>0) break;
            i--;
        }
        ans-= count[i] *i;
        best = ans;
        big+=count[i];
        while(i>=0){
            int j=i-1;
            while(j>=0){
                if(count[j]>0)break;
                j--;
            }
            if(j>=0){
                ans-=count[j] *(j);
                ans+= big*(i-j);
                big+=count[j];
                best = min(best, ans);
            }
            i=j;
        }
        cout<<max(0LL,best)<<endl;
    }
    return 0;
}

