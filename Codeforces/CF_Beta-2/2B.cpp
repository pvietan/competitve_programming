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

const int N = 1005;

int n, F[N][N], F2[N][N], F5[N][N], a[N][N], S, top;
char res[100005];

int chia(int x, int k) {
    if (!x) return 1000;
    int cnt = 0;
    for (; x%k==0; x /= k) cnt++;
    return cnt;
}

bool inside(int x, int y) {
    return (x>0&&x<=n&&y>0&&y<=n);
}

bool check(int x, int y, int k, int x2, int y2) {
    return inside(x,y)&&F[x][y]+k==F[x2][y2];
}

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d",&n);
    int tmpx = -1;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
        scanf("%d",&a[i][j]);
        if (!a[i][j])
            tmpx = i;
        if (i > 1 && j > 1) {
            F2[i][j] = min(F2[i-1][j],F2[i][j-1])+chia(a[i][j],2);
            F5[i][j] = min(F5[i-1][j],F5[i][j-1])+chia(a[i][j],5);
        }
        if (i == 1) {
            F2[i][j] = F2[i][j-1]+chia(a[i][j],2);
            F5[i][j] = F5[i][j-1]+chia(a[i][j],5);
        }
        if (j == 1) {
            F2[i][j] = F2[i-1][j]+chia(a[i][j],2);
            F5[i][j] = F5[i-1][j]+chia(a[i][j],5);
        }
    }
    if (F2[n][n] < F5[n][n]) {
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            F[i][j] = F2[i][j];
        S = 2;
    }
    else {
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            F[i][j] = F5[i][j];
        S = 5;
    }

    if (F[n][n]>1&&tmpx!=-1) {
        printf("1\n");
        for (int i = 1; i < tmpx; ++i)
            printf("D");
        for (int j = 1; j < n; ++j) printf("R");
        for (int i = 1; i <= n-tmpx; ++i)
            printf("D");
        return 0;
    }
    printf("%d\n",F[n][n]);
    int x = n, y = n;
    while (x!=1||y!=1) {
        if (check(x-1,y,chia(a[x][y],S),x,y)) {
            x--;
            res[++top] = 'D';
        }
        else {
            y--;
            res[++top] = 'R';
        }
    }
    for (int i = top; i > 0; --i)
        printf("%c",res[i]);
	return 0;
}
