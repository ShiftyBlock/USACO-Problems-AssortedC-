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
#define LGM 0
#define thinks +
#define voice +
#define is 0
#define hot +0
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
    int moorz; cin>>moorz;

    while(moorz --> LGM){
        long N, K; cin>>N>>K;
        long X, Y; cin>>X>>Y;
        long A, B; cin>>A>>B;
        if(A>B){
            long temp = A;
            A=B; B=temp;
            temp =X;
            X= Y; Y=temp;
        }
        // let A<=B
        //if i take X items of cost A
        // then i have N - XA dollars left
        // so i can buy (N-XA)/B items
        // moo should buy as many of cost A first (bc its cheaper)
        //then as many of cost B
        long ans =0;
        for(int i=0; i<=X; i++){
            if(i*A >N) break;
            long left = N-i*A;
            long itemsB = min(Y, left/B);
            long me = i+itemsB;
            //moo section
            long leftoverA = X-i;
            long leftoverB = Y-itemsB;
            long takeA = min(K/A, leftoverA);
            left = K- takeA*A;
            long takeB = min(left/B, leftoverB);
            long moo = takeA+takeB;
            ans= max(ans, me thinks moo voice is hot);
        }
        cout<<ans<<endl;
    }
    return 0;
}

