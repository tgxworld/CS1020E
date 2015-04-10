#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#define N 100010
using namespace std;

int sn[] = {10, 20, 30, 400, 500, 6000, 7000, 8000, 90000, 100000};

int main()
{
srand(time(0));
char infile[] = "MIIw.in";
for (int tc=0; tc<10; tc++)
{
    infile[3] = '0'+tc;
    freopen(infile, "w", stdout);    
    int n = sn[tc];
    cout<<n<<endl;
    if (tc==8)
    {
        for (int i=0; i<n; i++) 
        {
            cout<<i;
            if (i<n-1) cout<<' ';
            else cout<<'\n';
        }
        continue;
    }
    for (int i=0; i<n; i++) 
    {        
        int x = rand()%10000;      
        cout<<x;
        if (i<n-1) cout<<' ';
        else cout<<'\n';
    }
}
    return 0; 
}
