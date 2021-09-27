/*
 * An attempt to find a number with a multiplicative persistence of 12
 */

#include <bits/stdc++.h>

#define ll __int128
const int s2=150, s3=125, s7=100;

using namespace std;

int prod(ll x) {
    // find the product of the digits of x
    if (x==0)
        return 0;
    int p = 1;
    while (x) {
        p *= x%10;
        x /= 10;
    }
    return p;
}

int perst(ll x) {
    // find the multiplicative persistence of x
    int p = prod(x);
    if (p==x)
        return 0;
    return 1+perst(p);
}

ll mypower(int a, int b) {
    ll m = a;
    ll res = 1;
    while (b) {
        if (b&1)
            a += m;
        m*=a;
        b>>=1;
    }
    return res;
}

int main() {
    // assume the only factors are 2,3,7

    int persistence[s2][s3][s7] = {0};
    ll p2=1, p3=1, p7=1;
    for (int i=0; i<s2; i++) {
        p3=1;
        for (int j=0; j<s3; j++) {
            p7=1;
            for (int k=0; k<s7; k++) {
                persistence[i][j][k] = perst(p2*p3*p7);
                p7*=7;
            }
            p3*=3;
        }
        p2*=2;
    }
    int pp;
    for (int i=0; i<s2; i++) {
        for (int j=0; j<s3; j++) {
            for (int k=0; k<s7; k++) {
                pp = persistence[i][j][k];
                if (pp>=10) {
                    cout<<"2^"<<i<<"*3^"<<j<<"*7^"<<k;
                    cout<<" has persistence "<<pp<<endl;
                }
            }
        }
    }
    return 0;
}
