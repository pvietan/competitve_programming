#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

ll p1, p2, v1, v2, st[5000], res;
int k;

void DQ(ll x) {
    if (x > 4444444444LL) return;
    if (x) st[++st[0]] = x;
    DQ(x*10+4); DQ(x*10+7);
}

int main() {
	freopen("input.txt","r",stdin);
    scanf("%I64d%I64d%I64d%I64d%d",&p1,&p2,&v1,&v2,&k);
    DQ(0);
    sort(st+1,st+st[0]+1);
    ll L = p1;
    while (L <= p2) {
        int s1 = upper_bound(st+1,st+st[0]+1,L)-st;
        ll R = min(st[s1]-1,p2);
        s1--;
        if (s1 < k) {
            L = R+1;
            continue;
        }
        ll L2, R2;
        if (s1 == k) {
            L2 = 0;
            R2 = 3;
        }
        else {
            L2 = st[s1-k];
            R2 = st[s1-k+1]-1;
        }
        if (R2 < v1-1 || L2 > v2-1) {
            L = R+1;
            continue;
        }
        L2 = max(L2,v1-1), R2 = min(R2,v2-1);
        res += (R-L+1)*(R2-L2+1);
        L = R+1;
    }
    L = p1-1;
    while (L <= p2-1) {
        int s1 = upper_bound(st+1,st+st[0]+1,L)-st;
        ll R = min(st[s1]-1,p2-1);
        s1--;
        ll L2, R2;
        if (s1+k >= st[0]) {
            L = R+1;
            continue;
        }
        L2 = st[s1+k];
        R2 = st[s1+k+1]-1;
        L2 = max(L2,v1), R2 = min(R2,v2);
        if (L2 > R2) {
            L = R+1;
            continue;
        }
        res += (R-L+1)*(R2-L2+1);
        L = R+1;
    }
    if (k==1) {
        for (int i = 1; i <= st[0]; ++i)
            if (st[i] >= p1 && st[i] <= p2 && st[i] >= v1 && st[i] <= v2) res--;
    }
    double res2 = res;
    p1 = (p2-p1+1)*(v2-v1+1); double p3 = p1;
    printf("%.10lf\n",min(res2/p3,1.0));
	return 0;
}
