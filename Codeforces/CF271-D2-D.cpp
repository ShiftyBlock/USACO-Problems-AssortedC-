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
    string s; cin>>s;
    int N = s.size();
    string random; cin>>random;

    long MOD=(long) 1e9+7;
    long MOD2 = 123456701;
    long rolling1 = 29;
    long rolling2 = 31;
    set<pii> hash;
    v<int> num;
    for(int i=0; i<26; i++){
        num.emplace_back(random[i]-'0');
    }
    int K;cin>>K;
    for(int i=0; i<N; i++){
        long cur1=0;
        long cur2 =0;
        int bad=0;
        for(int j=i; j<N; j++){
            if(num[s[j]-'a']==0){
                bad++;
            }
            if(bad>K) break;
            cur1+=(s[j]-'a' +1) + cur1*rolling1;
            cur1%=MOD;
            cur2+=(s[j]-'a' +1) + cur2* rolling2;
            cur2%=MOD;
            hash.emplace(cur1,cur2);
        }
    }
    cout<<hash.size()<<endl;
    return 0;
}

