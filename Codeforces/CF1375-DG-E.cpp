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

/*
Let's assume all elements are distinct: ie we have a permutation of an array n
Like
5 1 3 4 2
Now, we also have to use all of our inversions
(1,2) (1,3) (1,4) (1,5) (3,5) (4,5)
So in order for us to make sure there are no contradictions
We process the array such that we are able to remove the last element
And just work on the remaining
This also just means make a_n = n
But even with making a_n = n, we also need to guarantee our inversion structure
Which means that the relative positions of the array elements need to stay the same
other than a_n, which is now at the end

Going down this path, we realize that if we use the a_n position as our "pivot point"
which means that we swap (x, n) pairs
Then the way to preserve our inversion structure (relative positions)
Is to process the (x, n) in increasing order of array[x]

So let's deal with n, 5
Our swaps are (1,5) (3,5) (4,5)
And a_1 = 5 , a_3 = 3 , a_4 = 4
So we should process in order of
a_3, a_4, a_1
By doing so, we now end up with
4 1 2 3 5

The relative ordering of the first 4 elements stay the same
As in, assuming the original array is a, and the new one is b
if a_i > a_j then b_i > b_j
if a_i < a_j then b_i < b_j
(note that they wont be the same because all values are distinct)

Now that we preserved our relative orderings
we can repeat our process, but this time process n-1, which is 4
The only pair inversion is (1,4)
3 1 2 4 5

Process (1,3)
2 1 3 4 5

Process (1,2)
1 2 3 4 5

Done.

Something else that the editorial points out, is how the elements are all decreasing by one
As in, anything that makes an inversion with the element in processing
is subtracted by 1
and the element becomes the index

Now, what if the array isn't a permutation (elements are not distinct?)
We can make this logical jump:
You can compress the array into 0...n-1
And therefore solve on a permutation
Because repeats don't change the answer anyways
And we aren't rquired to minimize inversions
*/
v<int> arr;
bool cmp (pii x, pii y){
    //increasing order of arr value
    return arr[x.second] < arr[y.second];
}

int main() {
    setIO("", 0);
    int N; cin>>N;
    v<pii> temp;
    for(int i=0; i<N; i++){
        int num; cin>>num; temp.emplace_back(num, i);
    }
    sort(temp.begin(), temp.end());
    arr.resize(N);
    for(int i=0; i<N; i++){
        arr[temp[i].second]=i;
    }
    // we now have permutation
    // now generate our inversions?
    v<pii> pairs;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            // reverse because we're going to process in order of second
            if(arr[i]> arr[j]) pairs.emplace_back(j,i);
        }
    }
    sort(pairs.begin(), pairs.end());
    reverse(pairs.begin(), pairs.end());
    cout<<pairs.size()<<endl;
    // process from n to 0
    for(int i=0; i<pairs.size();){
        int cur = pairs[i].first;
        int j=i;
        while(j<pairs.size()){
            if(pairs[j].first != cur) break;
            j++;
        }
        // j is exclusive, [i, j)
        v<pii> pending;
        for(int k=i; k<j; k++){
            pending.emplace_back(pairs[k]);
        }
        sort(pending.begin(), pending.end(), cmp);
        for(pii p: pending){
            int temp = arr[p.second];
            arr[p.second] = arr[p.first];
            arr[p.first]=temp;
            cout<<p.second+1<<" "<<p.first+1<<endl;
        }
        i=j;
    }

    return 0;
}

