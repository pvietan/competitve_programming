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

bool visited[100005];
int qu[100005], n, F[100005];
vector <int> adj[100005];

bool check(int x) {
    while (x) {
        if (x%10 != 7 && x%10 != 4) return false;
        x /= 10;
    }
    return true;
}

void bfs(int u) {
    int fr = 1, re = 1;
    qu[1] = u;
    while (fr <= re) {
        int u = qu[fr++];
        visited[u] = true;
        for (int i = 0; i < sz(adj[u]); ++i) {
            int v = adj[u][i];
            if (visited[v]) continue;
            qu[++re] = v;
        }
    }
    for (int i = 1; i <= re; ++i)
        F[qu[i]] = re;
}

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for (int i = 1; i < n; ++i) {
        int u, v, c;
        scanf("%d%d%d",&u,&v,&c);
        if (check(c)) continue;
        adj[u].pb(v); adj[v].pb(u);
    }
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) bfs(i);
    ll res = 0, m = n;
    for (int i = 1; i <= n; ++i)
        res += (m-1-F[i])*(m-F[i]);
    cout << res << endl;
	return 0;
}
