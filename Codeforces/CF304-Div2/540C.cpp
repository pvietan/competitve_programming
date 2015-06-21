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

const int N = 505;
const int mov[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool b;
int qu[N*N][2], fr, re, n, m, u, v, x, y;
char a[N][N];
bool visit[N][N];

bool inside(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int cnt(int x, int y) {
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        int x2 = x+mov[i][0], y2 = y+mov[i][1];
        res += (inside(x2,y2)&&a[x2][y2]=='.');
    }
    return res;
}

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d%d\n",&n,&m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) scanf("%c",&a[i][j]);
        scanf("\n");
    }
    scanf("%d%d%d%d",&u,&v,&x,&y);
    if (u==x && v==y) {
        if (cnt(u,v))
            printf("YES");
        else printf("NO");
        return 0;
    }
    a[u][v] = '.';
    fr = re = 1;
    if (a[x][y]=='X') b = true;
    a[x][y] = '.';
    qu[1][0] = u, qu[1][1] = v;
    visit[u][v] = true;
    while (fr <= re) {
        int x = qu[fr][0], y = qu[fr][1];
        fr++;
        for (int i = 0; i < 4; ++i) {
            int x2 = x+mov[i][0], y2 = y+mov[i][1];
            if (inside(x2,y2)&&!visit[x2][y2]&&a[x2][y2]=='.') {
                re++;
                qu[re][0] = x2, qu[re][1] = y2;
                visit[x2][y2] = true;
            }
        }
    }
    if (!visit[x][y]) {
        printf("NO");
        return 0;
    }
    if (b) printf("YES");
    else {
        if (cnt(x,y)>1) printf("YES");
        else printf("NO");
    }
	return 0;
}
