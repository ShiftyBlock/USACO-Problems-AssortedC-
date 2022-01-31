/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define v vector
#define double long double
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
double X,Y,C;
double cost(int mid){
    double temp= ((mid+1)*X + mid*Y)/(2*mid+1);
    return temp;
}
//mixing water
int main() {
    setIO("", 0);
    setprecision(15);
    int tcs; cin>>tcs;
    while(tcs-->0) {
        cin >> X >> Y >> C;
        if(X<=C){
            cout<<1<<endl;
            continue;
        }
        if (2*C <= (X + Y) ) {
            cout << 2 << endl;
            continue;
        }
        int low = floor((double) (C - X) / (X + Y - 2 * C));
        double best = 1<<30;
        for(int i=max(0, low-5); i<=low+5; i++){
            best = min(best, abs(C-cost(i)));
        }
        for(int i=max(0, low-5); i<=low+5; i++){
            if(abs(abs(C-cost(i)) - best)==0){
                cout<<i+i+1<<endl;
                break;
            }
        }

    }
    return 0;
}

