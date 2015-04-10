#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#define N 100010
using namespace std;

int arr[N];

int main()
{
char infile[] = "MIIw.in";
char outfile[] = "MIIw.out";
for (int tc=0; tc<10; tc++)
{
    infile[3] = outfile[3] = '0' + tc;
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long tot = 0;
    int cnt=1;
    for (int i=1; i<n; i++)
    {
        if (arr[i]>arr[i-1]) cnt++;
        else 
        {
             long long temp = (long long) cnt * (long long) (cnt-1);
             temp /= 2;
             tot += temp;
             cnt = 1;
        }
    }
    long long temp = (long long) cnt * (long long) (cnt-1);
    temp /= 2;
    tot += temp;
    cnt = 1;
    cout<<tot<<endl;
}
    return 0;
}
        
        
    
