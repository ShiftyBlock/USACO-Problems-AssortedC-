/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define v vector
#define long long long


//strategy
// first give out 1
// it doesnt matter who eats it
// if the biggest ate it, kill
// otherwise, send out big - leftover
// the big will have to eat
// then kill

// to kill big
// send out a 2*big - small - medium
// it doesnt matter who eats it, as long as its either small or medium
// then send out the differences: these will be equal



signed main() {
    long a, b, c;
    cin>>a>>b>>c;
    v<long> arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    cout<<"First"<<endl;
    cout<<1<<endl;
    int num; cin>>num;
    if(num==0) exit(0);
    num--;
    arr[num]+=1;
    //kill function
    if(arr[num] == max(arr[0], max(arr[1], arr[2]))){
        long other1 = (num+1)%3;
        long other2 = (num+2) %3;
        cout<<2*arr[num] - arr[other1] - arr[other2]<<endl;
        int nn; cin>>nn;
        if(nn==0 ) exit(0);
        nn--;
        arr[nn]+= 2*arr[num] - arr[other1] - arr[other2];
       // cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        cout<<(arr[nn] - min(arr[0], min(arr[1], arr[2])))/2L<<endl;
    }
    else{
        long other1 = (num+1)%3;
        long other2 = (num+2) %3;
        long other = -1;
        long big = max(arr[0], max(arr[1], arr[2]));
        if(arr[other2] != big) other = arr[other2];
        else other = arr[other1];
        cout<<big - other<<endl;
        cin>>num;
        if(num==0) exit(0);
        num--;
        arr[num]+=big-other;
        other1 = arr[(num+1)%3];
        other2 = arr[(num+2) %3];
        //cout<<arr[num]<<endl;
        //cout<<other1<<endl;
        //cout<<other2<<endl;
        cout<<2*arr[num] - other1 - other2<<endl;

        int nn; cin>>nn;
        if(nn==0 ) exit(0);
        nn--;
        arr[nn]+= 2*arr[num] - other1 - other2;
        //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        cout<<(arr[nn] - min(arr[0], min(arr[1], arr[2])))/2L<<endl;
    }


    return 0;
}

