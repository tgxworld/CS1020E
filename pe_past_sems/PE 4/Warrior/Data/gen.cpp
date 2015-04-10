#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
int sn[] = {5, 5, 7, 10, 12, 15, 17, 18, 19, 20};
int sm[] = {3, 4, 10, 15, 20, 30, 35, 40, 45, 50};

bool hav[30][30];

int main(){
char infile[]="warriorw.in";
srand(time(0));
for (int tc=0; tc<10; tc++){
    infile[7] = '0'+tc;
    freopen(infile, "w", stdout);
    int N = sn[tc];
    int M = sm[tc];
    cout<<N<<' '<<M<<endl;
    for (int i=1; i<=N; i++) cout<<(1+rand()%(N*2/3)) * 10<<endl;
    memset(hav, false, sizeof(hav));
    while (M-->0){
        int x = rand()%N + 1;
        int y = rand()%N + 1;
        if (x==y || hav[x][y] || hav[y][x]){
            M++;
            continue;
        }
        cout<<x<<' '<<y<<endl;
        hav[x][y] = hav[y][x] = true;
    }  
}    

    return 0;
}
