//
// Created by yuu on 2019/12/02.
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


int main(void){
    int N;
    cin>>N;

    bool flag = false;
    for (int i = 2; i < 100; ++i) {
        for (int k = 2; k < 100; ++k) {
            if(i*k > N)break;

            if(i*k == N){
                flag = true;
                break;
            }
        }
    }

    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }



    return 0;
}