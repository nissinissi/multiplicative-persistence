#include <bits/stdc++.h>

#define ll __int128
const int s0=150, s1=125, s2=100;   	// the exponents of the factors

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

int main() {
    int f[] = {2,3,7};      // the possible factors

    // in the loop below, the persistence of the following number is checked (^ denotes raising to a power):
    // f[0]^i * f[1]^j * f[2]^k
    int persistence[s0][ s1][ s2] = {0};
    ll p0=1, p1=1, p2=1;
    for (int i=0; i < s0; i++) {
        p1=1;
        for (int j=0; j < s1; j++) {
            p2=1;
            for (int k=0; k < s2; k++) {
                persistence[i][j][k] = perst(p0 * p1 * p2);
                p2*=f[2];
            }
            p1*=f[1];
        }
        p0*=f[0];
    }

    ofstream ofile;
    ofile.open("results.txt");
    ofile<<"results for "<<f[0]<<","<<f[1]<<","<<f[2]<<":"<<std::endl;
    int pp;
    for (int i=0; i < s0; i++) {
        for (int j=0; j < s1; j++) {
            for (int k=0; k < s2; k++) {
                pp = persistence[i][j][k];
                if (pp>=10) {
                    ofile<<f[0]<<"^"<<i<<"*"<<f[1]<<"^"<<j<<"*"<<f[2]<<"^"<<k;
                    ofile<<" has persistence "<<pp<<std::endl;
                }
            }
        }
    }
    ofile.close();
    return 0;
}
