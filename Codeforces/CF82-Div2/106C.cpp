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

int F[12][1005], n, m, d0, c0, a[12], b[12], c[12], d[12], res;

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&c0,&d0);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    memset(F, -1, sizeof -1);
    for (int i = 0; i <= n/c0; ++i)
        F[0][n-c0*i] = d0*i;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j <= n; ++j)
        if (F[i][j]!=-1) {
            for (int k = 0; k <= min(j/c[i+1],a[i+1]/b[i+1]); ++k)
                F[i+1][j-c[i+1]*k] = max(F[i+1][j-c[i+1]*k],F[i][j]+d[i+1]*k);
        }
    for (int i = 0; i <= m; ++i)
    for (int j = 0; j <= n; ++j)
        res = max(res,F[i][j]);
    cout << res << endl;
	return 0;
}
