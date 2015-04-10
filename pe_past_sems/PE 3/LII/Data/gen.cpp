#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int sn[]={10, 20, 30, 40, 50, 70, 80, 800, 2800, 99000};

int main(){
char infile[]="LIIw.in";
srand(time(0));
for (int tc=0; tc<10; tc++){
    infile[3]='0'+tc;
    freopen(infile, "w", stdout);
    int N = sn[tc];
    cout<<N<<endl;
    for (int i=1; i<N; i++){
        cout<<rand()%1000000<<' ';
    }
    cout<<rand()%10000000<<endl;
}
    return 0;
}
        
