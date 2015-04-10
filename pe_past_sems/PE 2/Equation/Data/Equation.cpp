#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

char strA[12];
char strB[12];
char strC[12];
bool hav[11];
int occ[11];
int val[11];
int ans;

int getval(char * str)
{
    int n = strlen(str);
    int res = 0;
    for (int i=0; i<n; i++) res = res*10 + val[str[i]-'A'];  
    return res;
}

void dfs(char x)
{
    if (x>'G') 
    {
        int a = getval(strA);
        int b = getval(strB);
        int c = getval(strC);
        if (a+b==c) 
        {
         //   cout<<a<<' '<<b<<' '<<c<<endl;
            ans++;
        }
        return;
    }
    if (occ[x-'A']==0) 
    {
        dfs(x+1);
        return;
    }
    for (int i=0; i<=9; i++)
    {
        if (hav[i]) continue;
        hav[i] = true;
        val[x-'A'] = i;
        dfs(x+1);
        hav[i] = false;
    }             
}
     
int main()
{
char fin[]= "Equationw.in";
char fout[]= "Equationw.out";
for (int tc=0; tc<10; tc++)
{
    fin[8] = fout[8] = '0' + tc;
    freopen(fin, "r", stdin);
    freopen(fout, "w", stdout);
    memset(hav, false, sizeof(hav));
    memset(occ, 0, sizeof(occ));
    scanf("%s", strA);
    scanf("%s", strB);
    scanf("%s", strC); 
    for (int i=0; i<strlen(strA); i++) occ[strA[i]-'A']++;
    for (int i=0; i<strlen(strB); i++) occ[strB[i]-'A']++;
    for (int i=0; i<strlen(strC); i++) occ[strC[i]-'A']++;    
    ans = 0;
    dfs('A');
    cout<<ans<<endl;   
}   
    return 0;    
}
