//
// Created by yuu on 2019/12/30.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <math.h>
#include <stack>
#include <queue>
#include <cstdio>

using namespace std;
bool pair_compare_by_first(pair<int, int> left, pair<int, int> right) {
    if(left.first != right.first){
        return left.first < right.first;
    }else{
        return left.second < right.second;
    }
}

int main(void){
    int T, P, Q;
    cin>>T>>P>>Q;
    vector<pair<int, int> > xy;

    for (int i = 0; i < Q-P+1; ++i) {
        int a, b;
        cin>>a>>b;

        xy.push_back(make_pair(a,b));
    }

    sort(xy.begin(), xy.end(), pair_compare_by_first);

    long long count = 0;
//    cout<<xy.size()<<endl;
    for (int i = 0; i < xy.size()-1; ++i) {
//        cout<<"xy[i].first ="<<xy[i].first<<endl;
        if(xy[i].second < 0 && xy[i+1].second > 0){
            count ++;
            continue;
        }
        if(xy[i].second > 0 && xy[i+1].second < 0) {
            count ++;
            continue;
        }
    }
//cout<<count<<endl;

    if(count >= T){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}