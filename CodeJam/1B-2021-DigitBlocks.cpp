/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define long long long
#define v vector

void setIO(string name, int submit) {


}
//WRONG

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    int N, B, P; cin>>N>>B>>P;
    while(tcs-->0){
        v<int> arr;
        for(int i=0; i<N*B; i++){
            arr.push_back(i);
        }
        reverse(arr.begin(), arr.end());
        v<int> height(N);
        int left=N;
        for(int i=0; i<N*B; i++){
            int num; cin>>num;
            bool big =false;
            for(int j=0; j<min(N, (int)arr.size()); j++){
                if(num == arr[j]){
                    big=true;
                }
            }
            arr.erase(find(arr.begin(), arr.end(), num));
            int maxh=-1;
            int maxhj=-1;
            bool used=false;
            for(int j=0; j<N; j++){
                if(height[j] == B) continue;
                if(big){
                    if(height[j] == B-1){
                        height[j] = B;
                        left--;
                        cout<<j+1<<endl;
                        used=true;
                        break;
                    }
                }
                if(height[j] > maxh && height[j] != B-1){
                    maxh = height[j];
                    maxhj = j;
                }
            }
            if(used) continue;
            for(int j=0; j<N; j++) {
                if (j==maxhj) {
                    height[j]++;
                    cout << j + 1 << endl;
                    continue;
                }
            }
        }
    }
    return 0;
}

