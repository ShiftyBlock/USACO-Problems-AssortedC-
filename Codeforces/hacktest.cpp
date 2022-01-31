#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
int main() {
    boost
    ll t;
    t=1;
    while (t--) {
        vector<int> arr;
        for(int i=1; i<=10; i++){
            arr.push_back(i*i*i);
        }
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cout<<arr[i]+arr[j]<<" ";
            }
            cout<<endl;
        }
    }
}


