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

const double oo = 1000000009;

int n;
double lx = oo, ly = oo, lz = oo, rx = -oo, ry = -oo, rz = -oo;

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        x[i] = a, y[i] = b, z[i] = c;
    }
    if (n==1) {
        printf("%.6lf %.6lf %.6lf",x[1],y[1],z[1]);
        return 0;
    }
    for (int i = 1; i < n; ++i)
    for (int j = i+1; j <= n; ++j) {
        double a = (x[i]+x[j])/2.0, b = (y[i]+y[j])/2.0, c = (z[i]+z[j])/2.0;

    }

	return 0;
}
