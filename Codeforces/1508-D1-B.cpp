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

//observation number 1
// the permutatations go up in increments of 2^0
// so the base 1 2 3 .. N counts as 1
// then if you permute 2 numbers you get 1
// if you permute 3 numbers you get 2
// if you permute 4 numbers you get 4
// 5: 8
// 6: 16
// and the sum of it is
// 1,2,4, 8, 16, 32
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; long K; cin>>N>>K;
        if(N<61){
            v<long> pow2(61); pow2[0] = 1;
            for(int i=1; i<61; i++){
                pow2[i] = pow2[i-1] *2;
            }
            if(pow2[N-1] < K){
                cout<<-1<<endl;
                continue;
            }
            if(N==1){
                cout<<1<<endl;
                continue;
            }
            int i=0;
            long low =0;
            long high=pow2[N-1];
            if(K==high){
                for(int k=N; k>=1; k--){
                    cout<<k<<" ";
                }
                cout<<endl;
                continue;
            }
            v<int> ans(N);
            int last=1;
            while(low!=high){
                if(i>=N) break;
                long mid = (low+high)/2;
                if(K>mid){
                    int element = last;
                    // if greater, increment element by 1
                    while(K> (low+high)/2 ){
                        element++;
                        low= (low+high)/2;
                    }
                    int temp = element;
                    while(element>=last){
                        ans[i] = element;
                        element--;
                        i++;
                    }
                    last  = temp+1;
                }
                if(K<=mid){
                    ans[i] = last;
                    last++;
                    i++;
                    high=mid;
                }
            }
            for(int j=0; j<N; j++){
                cout<<ans[j]<<" ";
            }
            cout<<endl;
        }
        /*
        if(N>=61){
            //get rid of the first N-61 elements
            //because we wont need them :)
            for(int i=0; i<=N-61; i++){
                cout<<i+1<<" ";
            }
        }*/
    }
    return 0;
}

