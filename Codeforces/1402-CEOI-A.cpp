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
//iterate over x for each N element
// find width of elements of height x
// then add [w*(w+1)] * [(x*(x+1))/2 -(x*(x-1))/2]
// this simplifies to [w*(w+1)] * x

int main() {
    setIO("", 0);
    int N; cin>>N;
    v<int> height, width;
    for(int i=0; i<N; i++){
        int num; cin>>num; height.push_back(num);
    }
    for(int i=0; i<N; i++){
        int num; cin>>num; width.push_back(num);
    }
    height.push_back(0);
    width.push_back(0);
    long ans =0;
    v<pii> arr;
    arr.emplace_back(0,0);
    for(int i=0; i<N+1;i++){
        long h= height[i];
        long cw =0;
        while(arr.back().first > h){
            cw+=arr.back().second;  cw%=MOD;
            long ch = arr.back().first - max(h, arr[(int)arr.size()-2].first) ;
            ch%=MOD;
            //below height
            long bh = ch * max(h, arr[(int)arr.size()-2].first);
            bh%=MOD;
            ans+=(cw*(cw+1)/2)%MOD * ((( ch*(ch+1)/2 + bh)%MOD));
            ans%=MOD;
            arr.pop_back();
        }
        if(arr.back().first == height[i]){
            arr.back().second+=cw+width[i];
        }
        else {
            arr.emplace_back(height[i], width[i]+cw);
        }
        arr.back().second%=MOD;
    }
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}

