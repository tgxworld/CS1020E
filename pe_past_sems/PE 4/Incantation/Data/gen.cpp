#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define N 100010
using namespace std;

int sn [] = {20, 20, 100, 100, 500, 500, 10000, 40000, 80000, 100000};
string dict[N];

void getdict(){
    string w;
    for (int i=0;;){
        w.clear();
        int len = rand()%8 + 3;
        while (len--){
            char ch = 'a' + rand()%26;
            w.push_back(ch);
        }
        dict[i] = w;
        i++;
        int k = rand()%3+1;
        while (k--) {
            dict[i] = w;
            i++;
        }
        if (i>=sn[9])break;
    }
}

int main(){
    getdict();
    char outfile[] = "incantationx.in";
    for (int tc=0; tc<10; tc++){
        outfile[11] = '0' + tc;
        freopen(outfile,"w",stdout);
        int n = sn[tc];
        for(int i=0; i<n*100; i++){
           int x = rand()%n;
           int y = rand()%n;
           string tem = dict[x]; 
           dict[x] = dict[y];
           dict[y] = tem;
        }
        cout<<n<<endl;
        for (int i=0; i<n; i++) cout<<dict[i]<<endl;
    }
    return 0;
}
        
