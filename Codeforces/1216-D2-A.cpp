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
    int N; cin>>N;
    string s; cin>>s;
    int a = 0;
    int b = 0;
    v<char> ans;
    int changes = 0;
    for(int i=0; i<N; i++){
        if(s[i]=='a') a++;
        if(s[i]=='b') b++;
        if(i%2==1){
            if(a>b) {
                changes++;
                a--; b++;
                ans.push_back('b');
            }
            else if(b>a){
                changes++;
                b--; a++;
                ans.push_back('a');
            }
            else if(a==b) ans.push_back(s[i]);
        }
        else {
            ans.push_back(s[i]);
        }
    }
    cout<<changes<<endl;
    for(char c: ans)
    {
        cout<<c;
    }
    cout<<endl;

    return 0;
}

