//
// Created by Myabu on 2019/12/30.
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


// https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(void){
    int N,Q;
    int A[10010];
//    int X[10010];
//    int Y[10010];

    UnionFind tree(10010);
    cin>>N>>Q;

    for (int i = 0; i < N; ++i) {
        cin>>A[i];
    }

    for (int i = 0; i < Q; ++i) {
        int x,y;
        cin>>x>>y;
        tree.unite(x, y);
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += tree.root(A[i]);
    }


    cout<<ans<<endl;

    return 0;
}