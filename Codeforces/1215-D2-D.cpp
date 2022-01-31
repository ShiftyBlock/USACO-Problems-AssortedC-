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
    string s; cin>>s;
    int sum1= 0;
    int q1=0;
    int sum2=0;
    int q2=0;
    for(int i=0; i<N/2; i++){
        if(s[i]=='?') {
            q1++;
        }
        else sum1+=s[i]-'0';
    }
    for(int i=N/2; i<N; i++){
        if(s[i]=='?') {
            q2++;
        }
        else sum2+=s[i]-'0';
    }
    if(q1>q2){
        int extra = (q1-q2)/2 *9;
        if(extra+sum1==sum2){
            cout<<"Bicarp"<<endl;
        }
        else cout<<"Monocarp"<<endl;
    }
    if(q1<q2){
        int extra = (q2-q1)/2 *9;
        if(extra+sum2==sum1){
            cout<<"Bicarp"<<endl;
        }
        else cout<<"Monocarp"<<endl;
    }
    if(q1==q2){
        int extra =0;
        if(extra+sum2==sum1){
            cout<<"Bicarp"<<endl;
        }
        else cout<<"Monocarp"<<endl;
    }
    return 0;
}

