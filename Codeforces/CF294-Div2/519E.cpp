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

const int N = 100005;
const int M = 20;

int n, l2[N], mu[M], H[N], pa[N][M], F[N];
vector <int> adj[N];

int tinh(int x) {
    int res = 0;
    for (; x; x /= 2) res++;
    return res-1;
}

void init() {
    for (int i = 1; i <= n; ++i)
        l2[i] = tinh(i);
    mu[0] = 1;
    for (int i = 1; mu[i-1] <= n; ++i)
        mu[i] = mu[i-1]*2;
}

void dfs(int u, int p) {
    H[u] = H[p]+1;
    pa[u][0] = p;
    for (int i = 1; i <= l2[H[u]]; ++i)
        pa[u][i] = pa[pa[u][i-1]][i-1];
    ///////////////////////
    F[u] = 1;
    for (int i = 0; i < sz(adj[u]); ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        dfs(v,u);
        F[u] += F[v];
    }
}

int lca(int u, int v) {
    if (H[u] < H[v]) swap(u,v);
    for (int i = l2[H[u]]; i >= 0; --i)
        if (H[pa[u][i]] >= H[v])
            u = pa[u][i];
    if (u == v) return u;
    for (int i = l2[H[u]]; i >= 0; --i)
    if (pa[u][i] != pa[v][i]) {
        u = pa[u][i];
        v = pa[v][i];
    }
    return pa[u][0];
}

int road(int x, int z) {
    int res = 0;
    for (int i = l2[H[x]]; i >= 0; --i)
    if (H[pa[x][i]] >= H[z]) {
        res += mu[i];
        x = pa[x][i];
    }
    return res;
}

int cha(int x, int L) {
    if (L==0) return x;
    for (int i = l2[H[x]]; i >= 0; --i)
    if (mu[i] <= L) {
        x = pa[x][i];
        L -= mu[i];
    }
    return x;
}

int main() {
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	init();
	for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d",&u,&v);
        adj[u].pb(v);
        adj[v].pb(u);
	}
	dfs(1,0);
    int m; scanf("%d",&m);
    while (m--) {
        int x, y;
        scanf("%d%d",&x,&y);
        if (x==y) {
            printf("%d\n",n);
            continue;
        }
        int z = lca(x,y);
        int l1 = road(x,z), l2 = road(y,z);
        if ((l1+l2)&1) {
            printf("0\n");
            continue;
        }
        int L = (l1+l2)>>1;
        if (H[x] < H[y]) swap(x,y);
        int TD = cha(x,L);
        if (TD == z) cout << n-F[cha(x,L-1)]-F[cha(y,L-1)] << endl;
        else  cout << F[TD] - F[cha(x,L-1)] << endl;
    }
	return 0;
}
