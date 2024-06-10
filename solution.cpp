#include <bits/stdc++.h>
using namespace std;

//code starts here
int sol(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int>cat(n);
    vector<int>time(n);

    vector<int>res;
    vector<int>hash;
    for(int i=0; i<n; ++i)cin>>cat[i];
    for(int i=0; i<n; ++i)cin>>time[i];

    // check for complete meal
    unordered_map<int,int>verify;
    for(auto it: cat)verify[it]++;
    if(verify.size() < k)return -1;

    while(k){
        int minElement = INT_MAX;
        int minIndex = 0;
        for(int i=0; i<time.size(); ++i){
            if(time[i] < minElement){
                minElement = time[i];
                minIndex = i;
            }
        }

        // check if category is already included
        int flag = 1;
        for(auto it: hash){
            if(cat[minIndex] == it)flag = 0;
        }
        if(flag){
            res.push_back(minElement);
            k--;
        }
        hash.push_back(cat[minIndex]);
        time[minIndex] = INT_MAX;
    }

    // total time required
    int sum = 0;
    for(auto it: res){
        sum += it;
    }
    return sum;
}
//code ends here

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;cin>>t;
    while(t--){
        cout<<sol()<<endl;
    }
    return 0;
}