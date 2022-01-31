/*
ID: davidzh8
PROG: subset
LANG: C++
 */
//yay shiftyblock wrote his own function
//shiftyblock orz
//izhang also orz
//but izhang impl is wacky hehe
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
//#define endl "\n"
#define long long long
#define v vector

long MOD = 1e9+7;

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
struct djset{
    v<int> arr;
    int n;
    djset(int x){
        arr.resize(x);
        n=x;
        for(int i=0; i<n; i++){
            arr[i]=i;
        }
    }
    int find(int cur){
        if(arr[cur]==cur) return cur;
        int par = find(arr[cur]);
        arr[cur] = par;
        return par;
    }
    bool merge (int x, int y){
        int a = find(x);
        int b = find(y);
        if(a==b) return false;
        arr[a] = b;
        return true;
    }
};
string binary(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
    return "0";
}
int matrix[2][16384];
int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    djset dj(M*2);
    int count = 0;
    int merges = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M/4; j++){
            char c; cin>>c;
            string temp = binary(c);
            for(int k=0; k<4; k++){
                matrix[i%2][j*4+k] = temp[k]-'0';
                if(matrix[i%2][j*4+k]==1) count++;
            }
        }
        /*for(int k=0; k<2; k++){
            for(int l=0; l<M; l++){
                cout<<matrix[k][l]<<" ";
            }
            cout<<endl;
        }
        for(int k=0; k<2*M; k++){
            cout<<dj.arr[k]<<" ";
        }
        cout<<endl;*/
        for(int j=0; j<M;j++ ){
            if(matrix[(i+1)%2][j] == 1 && matrix[i%2][j]==1){
                if(dj.merge(j, M+j)) merges++;
            }
            if(j>0 && matrix[i%2][j-1]==1 && matrix[i%2][j]==1){
                if(dj.merge(j+M, j-1+M)) merges++;
            }
        }
        //yay shiftyblock wrote his own function
        for(int j=0; j<2*M; j++) {
            dj.find(j);
        }
        for(int j=0; j<M; j++){
            dj.arr[j] = dj.arr[j+M]-M;
        }
        for(int j=M; j<2*M; j++){
            dj.arr[j] = j;
        }
    }
    cout<<count-merges<<endl;
    return 0;
}


