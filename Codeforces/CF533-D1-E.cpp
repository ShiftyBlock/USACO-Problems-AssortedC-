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
bool iscycle(v<char> s1, v<char> s2){
    bool same1 = (s1[0]==s2[0]) && (s1[1]==s2[1]) && (s1[2] && s2[2]);
    bool same2 = (s1[0]==s2[1]) && (s1[1]==s2[2]) && (s1[2] && s2[0]);
    bool same3 = (s1[0]==s2[2]) && (s1[1]==s2[0]) && (s1[2] && s2[1]);
    return same1|| same2|| same3;
}
int main() {
    setIO("", 0);
    int N; cin>>N;
    string a,b;
    cin>>a>>b;
    // 3 cases
    // 0 if impossible-> this means there are 2 non consecutive spots
    // 2 if only 1 spot has an issue
    // 1
    // if there are 2 consecutive out of place letters, or
    // if there are at most 3 consecutive positions out of place
    // and the letters form a cycle
    // SWA
    // SHW
    // as you can see, the only possible string is SHWA
    // SWAH
    // SAHW
    // you can only do SWAHW
    // but if you tried to do SWAH and SAWH
    // there is no way you can build it
    // the best string would be SWAWHW, and you remove 2 at least
    int bad=0;
    bool valid=true;
    for(int i=0; i<N; i++){
        if(a[i]!=b[i]){
            if(bad>0) {
                bad= 1<<30;

            }
            if(bad==1<<30){
                valid=false; break;
            }
            bad++;
            int j=i+1;
            if(j<N){
                if(a[j]!=b[j]){
                    int k=j+1;
                    if(k<N){
                        if(a[k]!=b[k]){
                            v<char> s1; s1.push_back(a[i]); s1.push_back(a[j]); s1.push_back(a[k]);
                            v<char> s2; s2.push_back(b[i]); s2.push_back(b[j]); s2.push_back(b[k]);
                            if(!iscycle(s1, s2)){
                                bad=1<<30;
                            }
                            i=k;
                            continue;
                        }
                    }
                    bad++;
                    i=j;
                    continue;
                }
            }
        }
    }
    if(!valid){
        cout<<0<<endl;
    }
    if(bad==2) cout<<1<<endl;
    if(bad==1) cout<<2<<endl;
    return 0;
}

