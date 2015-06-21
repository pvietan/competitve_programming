#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

double F[105][105][105];
int r, s, p;

double solve(int x, int y, int z) {
    if (F[x][y][z]>0.0)return F[x][y][z];
    if (x > r || y > s || z > p) return 0.0;
    double a = x, b = y, c = z;
    double d1, d2, d3;
    d1 = solve(x,y+1,z)*(a*(b+1))/(a*(b+1)+a*c+(b+1)*c);
    d2 = solve(x+1,y,z)*((a+1)*c)/((a+1)*b+(a+1)*c+b*c);
    d3 = solve(x,y,z+1)*(b*(c+1))/((c+1)*a+(c+1)*b+a*b);
    if (isnan(d1)) d1 = 0.0;
    if (isnan(d2)) d2 = 0.0;
    if (isnan(d3)) d3 = 0.0;
    F[x][y][z] = d1+d2+d3;
    if (F[x][y][z]==0.0) F[x][y][z] = 1.0;
    return F[x][y][z];
}

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d%d%d",&r,&s,&p);
    F[r][s][p] = 1.0;
    double t = solve(0,0,0);
    double res1 = 0.0, res2 = 0.0, res3 = 0.0;
    for (int i = r; i > 0; --i)
        res1 += F[i][0][0];
    for (int i = s; i > 0; --i)
        res2 += F[0][i][0];
    for (int i = p; i > 0; --i)
        res3 += F[0][0][i];
    cout << fixed << setprecision(10) << res1/(res1+res2+res3) << " " << res2/(res1+res2+res3) << " " << res3/(res1+res2+res3);
	return 0;
}
