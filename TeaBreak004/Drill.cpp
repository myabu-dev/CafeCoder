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


long long gcd(long long a, long long b) {
    if (a%b == 0)
        return b;

    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

void ans_out(long long ans, long long g, long long g_2){
    if(g/g_2 == 1){
        cout<<ans/g_2<<endl;
    }else{
        cout<<ans/g_2<<" "<<g/g_2<<endl;
    }
}

int main(void){
    long long n_1, d_1, n_2, d_2;
    string P;

    cin>>n_1>>d_1;
    cin>>P;
    cin>>n_2>>d_2;

    if(P[0] == '+'){
        long long g;
        g = lcm(d_1, d_2);
        n_1 *= g/d_1;
        n_2 *= g/d_2;

        long long ans;
        ans = n_1 + n_2;

        long long g_2;
        g_2 = gcd(ans, g);

        ans_out(ans, g, g_2);
    }else if(P[0] == '-'){
        long long g;
//        cout<<"n_2 ="<<n_2<<endl;
//        cout<<"n_1 ="<<n_1<<endl;

        g = lcm(d_1, d_2);

//        cout<<"g ="<<g<<endl;
        n_1 *= g/d_1;
        n_2 *= g/d_2;
//
//        cout<<"n_2 ="<<n_2<<endl;
//        cout<<"n_1 ="<<n_1<<endl;

        long long ans;
        ans = n_1 - n_2;

        long long g_2;
        g_2 = gcd(ans, g);

        ans_out(ans, g, g_2);
    }else if(P[0] == '*') {
        long long ans;
        ans = n_1 * n_2;
        long long D;
        D = d_1 * d_2;

        long long g_2;
        g_2 = gcd(ans, D);

        ans_out(ans, D, g_2);
    }else if(P[0] == '/'){
        long long temp = n_2;
        n_2 = d_2;
        d_2 = temp;

        long long ans;
        ans = n_1 * n_2;
        long long D;
        D = d_1 * d_2;

        long long g_2;
        g_2 = gcd(ans, D);

        ans_out(ans, D, g_2);
    }


    return 0;
}