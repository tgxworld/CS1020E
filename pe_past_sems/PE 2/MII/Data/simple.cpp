#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#define N 100010
using namespace std;

int a[N], n;
int b[N];
long long cnt;

int main()
{
char infile[] = "MIIw.in";
char outfile[] = "MIKw.out";
for (int tc=0; tc<10; tc++)
{
    infile[3] = outfile[3] = '0' + tc;
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    cnt = 0;
    for (int i=0; i<n; i++) 
    {
        for (int j=i+1; j<n; j++)
        {
            if (a[j]>a[j-1]) cnt++;
            else break;
        }
    }       
    cout<<cnt<<endl;
}
    return 0; 
}
