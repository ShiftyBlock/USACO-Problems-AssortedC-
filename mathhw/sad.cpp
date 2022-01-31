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
    int tcs; cin>>tcs; while(tcs-->0){
        int N;
        cin>>N;
        long top=0; long bot=0;
        for (int i = 0; i < N; ++i) {
            int M; cin>>M;
            for (int j = 0; j < M; ++j) {
                int num; cin>>num;
                if(num>0) top++;
                else bot++;
            }
        }
        cout<<top*bot<<endl;
    }
    return 0;
}

