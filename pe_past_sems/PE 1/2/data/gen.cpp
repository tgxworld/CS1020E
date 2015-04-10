#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#define N 100010
using namespace std;

int sn[] = {4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
int a[11][11];

int main()
{
srand(time(0));
char infile[] = "rubaiyatw.in";
for (int tc=0; tc<10; tc++)
{
    infile[8] = '0'+tc;
    freopen(infile, "w", stdout);    
    int n = sn[tc];
    cout<<n<<endl;
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) a[i][j] = rand()%100;
    int stx = rand()%n;
    int sty = rand()%n;
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++)
        {            
            int neg = rand()%4;
            int x = a[i][j];
            if (neg==0) x = -x;
            if (stx==i && sty==j) cout<<'*';
            else cout<<x;
            if (j<n-1) cout<<' ';
            else cout<<'\n';
        }
    }
}
    return 0; 
}
