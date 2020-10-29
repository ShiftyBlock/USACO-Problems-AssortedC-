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
    while(tcs-->0)
    {
    	long x1, y1, x2, y2;
    	cin>> x1>>y1>>x2>>y2;
    	long res= abs(x2-x1)+abs(y2-y1);
    	if(y2!=y1 &&x2!=x1) res+=2;
    	cout<<res<<endl;

    }

    return 0;
}
