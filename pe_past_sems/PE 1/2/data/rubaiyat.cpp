#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#define N 11
#define maxn 100000000
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;
int a[N][N];
bool hav[N][N];
int stx, sty;
int ans;
vector<int> bestUt;

void dfs(int x, int y, int step, int tot, vector<int> ut)
{
    if (step==0)
    {
        if (tot>ans) 
        {
            ans = tot;
            bestUt = ut;
        }
        return;
    }
    
    hav[x][y] = true;
    
    for (int d=0; d<4; d++)
    {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if (xx<0 || yy<0 || xx>=n || yy>=n) continue;
        if (hav[xx][yy]) continue;
        ut.push_back(a[xx][yy]);
        dfs(xx, yy, step-1, tot+a[xx][yy], ut);
        ut.erase(ut.begin()+ut.size()-1);
    }
    
    hav[x][y] = false;  
}

int main()
{
    
char infile[] = "rubaiyatw.in";
char outfile[] = "rubaiyatw.out";
for (int tc=0; tc<10; tc++)
{
    infile[8] = outfile[8] = '0' + tc;
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    
    char str[10];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%s", str);
            if (str[0]=='*') 
            {
                stx = i;
                sty = j;
                a[i][j] = 0;
            }
            else if (str[0]=='-')
            {
                 int num = 0;
                 for (int k = 1; k<strlen(str); k++) num = num*10 + str[k]-'0';
                 a[i][j] = -num;
            }
            else
            {
                 int num = 0;
                 for (int k = 0; k<strlen(str); k++) num = num*10 + str[k]-'0';
                 a[i][j] = num;
            }
        }               
    }
    ans = -maxn;
    memset(hav, false, sizeof(hav));
    vector<int>ut;
    ut.clear();
    dfs(stx, sty, 10, 0, ut);
    cout<<ans<<endl;
   // for (int i=0; i<bestUt.size(); i++) cout<<bestUt[i]<<' '; cout<<endl;
}
    return 0;
}
    
    
