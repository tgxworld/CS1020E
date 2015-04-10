#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#define N 100010
using namespace std;

int a[N], n;
int b[N];
int cnt;

void merge(int l, int r)
{
    if (l==r) return;
    int mid = (l+r)>>1;
    merge(l, mid);
    merge(mid+1, r);
    
    int i = l, j = mid+1, k = l;
    while (i<=mid && j<=r)
    {
        if (a[i]<a[j])
        {
            cnt += (r-j+1);
            b[k++] = a[i];
            i++;
        }
        else
        {
            b[k++] = a[j];
            j++;
        }
    }
    while (i<=mid) { b[k++] = a[i]; i++;}
    while (j<=r) { b[k++] = a[j]; j++;}
    for (int i=l; i<=r; i++) a[i] = b[i];
}

int main()
{
   // freopen("psi.in", "r", stdin);
  //  freopen("psi.out", "w", stdout);
    
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=1; i<n; i++) a[i] += a[i-1];
    cnt = 0;
    merge(0, n-1);
    for (int i=0; i<n; i++) if (a[i]>0) cnt++;
    cout<<cnt<<endl;
    return 0; 
}
