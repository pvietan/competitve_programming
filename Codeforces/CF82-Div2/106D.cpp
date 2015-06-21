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
#define x first
#define y second

typedef long long ll;
typedef pair<int,int> ii;

int n, m, top, len[100005], F1[1005][1005], F2[1005][1005];
ii F[30];
char ans[30], dir[100005], a[1005][1005];

bool outside(int x, int y) {
    return (x < 1 || x > n || y < 1 || y > m);
}

int tinh1(int x, int y1, int y2) {
    if (y1 > y2) swap(y1,y2);
    return F1[x][y2]-F1[x][y1-1];
}

int tinh2(int y, int x1, int x2) {
    if (x1 > x2) swap(x1,x2);
    return F2[x2][y]-F2[x1-1][y];
}

void tinh(int x, int y, int i, int & x2, int & y2) {
    int dx = 0, dy = 0;
    if (dir[i]=='N') dx = -1;
    else if (dir[i]=='S') dx = 1;
    else if (dir[i]=='W') dy = -1;
    else if (dir[i]=='E') dy = 1;
    x2 = x+dx*len[i], y2 = y+dy*len[i];
}

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d%d\n",&n,&m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%c",&a[i][j]);
            if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
                F[a[i][j]] = ii(i,j);
                a[i][j] = '.';
            }
        }
        scanf("\n");
    }
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        F1[i][j] = F1[i][j-1] + (a[i][j]=='#');
        F2[i][j] = F2[i-1][j] + (a[i][j]=='#');
    }
    int k;
    scanf("%d\n",&k);
    for (int i = 1; i <= k; ++i)
        scanf("%c %d\n",&dir[i],&len[i]);
    for (char t = 'A'; t <= 'Z'; ++t)
    if (F[t].x != 0) {
        int x = F[t].x, y = F[t].y;
        bool b = true;
        for (int i = 1; i <= k; ++i) {
            int x2, y2; tinh(x,y,i,x2,y2);
            if (outside(x2,y2) || (x2==x&&tinh1(x,y,y2)!=0) || (y2==y&&tinh2(y,x,x2)!=0)) {
                b = false;
                break;
            }
            x = x2, y = y2;
        }
        if (b) ans[++top] = t;
    }
    if (!top) cout << "no solution" << endl;
    else {
        for (int i = 1; i <= top; ++i)
            printf("%c",ans[i]);
    }
	return 0;
}
