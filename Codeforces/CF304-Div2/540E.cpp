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

struct gt {
    int x, y;
};

const int N = 200005;

map <int,int> F;
gt a[N];
int b[N], c[N], mx, tmp[N], d[N], m, n, f[N];
ll T[N], ft[N];

bool cmp(gt u, gt v) {
    return u.x < v.x;
}

void nen() {
    for (int i = 1; i <= m; ++i)
        tmp[i] = a[i].y;
    sort(tmp+1,tmp+m+1);
    for (int i = 1; i <= m; ++i) {
        d[i] = lower_bound(tmp+1,tmp+m+1,a[i].y)-tmp;
        mx = max(mx,d[i]);
    }
}

void update(int x, ll k) {
    for (; x <= mx; x += x & -x)
        ft[x] += k;
}

int retrieve(int x) {
    ll res = 0;
    for (; x; x -= x & -x)
        res += ft[x];
    return res;
}

ll query(int l, int r) {
    int u = lower_bound(f+1,f+m+1,l)-f;
    if (u == m+1) return 0;
    int v = upper_bound(f+1,f+m+1,r)-f-1;
    return v-u+1;
}

ll solve1(gt x) {
    ll y = lower_bound(c+1,c+c[0]+1,x.x)-c, z = x.y-1;
    if (y==c[0]+1) return 0;
    y = c[y]+1;
    if (y > z) return 0;
    return z-y+1LL-query(y,z);
}

ll solve2(gt x) {
    ll y = upper_bound(b+1,b+b[0]+1,x.x)-b-1, z = x.y+1;
    if (y==0) return 0;
    y = b[y]-1;
    if (z > y) return 0;
    return y-z+1LL-query(z,y);
}

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        int a, b; scanf("%d%d",&a,&b);
        if (!F[a]) F[a] = a;
        if (!F[b]) F[b] = b;
        swap(F[a],F[b]);
    }
    for (map<int,int> ::iterator it = F.begin(); it != F.end(); ++it) {
        ++m;
        a[m].x = f[m] = it->first;
        a[m].y = it->second;
    }
    sort(a+1,a+m+1,cmp);
    for (int i = 1; i <= m; ++i) {
        if (!F[a[i].x-1]) b[++b[0]] = a[i].x;
        if (!F[a[i].x+1]) c[++c[0]] = a[i].x;
    }
    nen();
    for (int i = m; i > 0; --i) {
        T[i] = retrieve(d[i]-1);
        update(d[i],1);
    }
    ll res = 0;
    for (int i = 1; i <= m; ++i)
        res += T[i] + solve1(a[i]) + solve2(a[i]);
    cout << res << endl;
	return 0;
}
