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
        map<int, int> m;
        for(int i=0; i<N; i++){
            int num; cin>>num;
            if(m.find(num)==m.end()) m.emplace(num, 0);
            m[num]++;
        }
        v<int> arr;
        for(auto key: m){
            //we only care about at most 4 sticks
            if(key.second>=2) arr.push_back(key.first);
            if(key.second>=4) arr.push_back(key.first);
        }
        sort(arr.begin(), arr.end());
        //idea
        //if we're going to try to use i
        // and we can only use pairs up to i
        // then we're just going to use i-1
        double MIN =1<<30;
        int a=-1;
        int b =-1;
        for(int i=1; i<arr.size(); i++){
            double thing = (double)((arr[i]*2 +arr[i-1] *2)*(arr[i]*2 +arr[i-1] *2))/ (double)(arr[i] * arr[i-1]);
            if(thing<MIN){
                MIN = thing;
                a= arr[i];
                b= arr[i-1];
            }
        }
        cout<<a<<" "<<a<<" "<<b<<" "<<b<<endl;

    }
    return 0;
}

