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
char infile[] = "psiw.in";
char outfile[] = "ptiw.out";
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
        int sum = 0;
        for (int j=i; j<n; j++)
        {
            sum += a[j];
            if (sum>0) cnt ++;
        }
    }       
    cout<<cnt<<endl;
}
    return 0; 
}
