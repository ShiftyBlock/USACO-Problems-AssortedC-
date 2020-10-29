#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
#define rep(i,a,b) for(int i=a; i<b; i++)
void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("", 0);

    int tcs;
    cin>>tcs;
    while(tcs-->0){
        int N;
        string s;
        cin>> N>> s;
        bool allsame=true;
        char cur='>';
        for(char c: s){
            if(c=='-') continue;
            allsame&=cur==c;
        }
        if(!allsame){
            allsame=true;
            cur='<';
            for(char c: s){
            if(c=='-') continue;
            allsame&=cur==c;
            }
        }
        int res=0;
        for (int i = 0; i < N; ++i)
        {
            if(s[i]=='-' || s[(i+N-1)%N]=='-'){
                res++;
            }
            else if(s[i]=='>' || s[i]=='<'){
                if(allsame) res++;
            }
        }
        cout<<res<<endl;
    	
    }

    return 0;
}
