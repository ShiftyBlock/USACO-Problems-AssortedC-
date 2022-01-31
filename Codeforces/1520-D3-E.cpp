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
    while(tcs-->0){
        int N; cin>>N;
        string s;
        cin>>s;
        v<long> prefix;
        bool first = false;
        int last = -1;
        for(int i=0; i<N; i++){
            if(s[i] == '*'){
                if(first==false){
                    prefix.push_back(0);
                    first=true;
                    last = i;
                }
                else{
                    prefix.push_back(i-last-1);
                    last = i;
                }
            }
        }
        for(int i=1; i<prefix.size(); i++){
            long gap = prefix[i];
            prefix[i] = prefix[i-1] + gap*i;
        }
        reverse(s.begin(), s.end());
        v<long> suffix;
        first = false;
        last = -1;
        for(int i=0; i<N; i++){
            if(s[i] == '*'){
                if(first==false){
                    suffix.push_back(0);
                    first=true;
                    last = i;
                }
                else{
                    suffix.push_back(i-last-1);
                    last = i;
                }
            }
        }
        for(int i=1; i<suffix.size(); i++){
            long gap = suffix[i];
            suffix[i] = suffix[i-1] + gap*i;
        }
        reverse(suffix.begin(), suffix.end());
        long best = (long) 100000000000000000L;
        for(int i=0; i<suffix.size(); i++){
            best = min(best, suffix[i] + prefix[i]);
        }
        if(best == 100000000000000000L) best = 0;
        cout<<best<<endl;
    }

    return 0;
}

