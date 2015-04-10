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
  //  freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);
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
        
        
    
