#include <iostream>
using namespace std;

int N, M, K;
int value[21];
bool react[21][21];

void dfs(int x, bool chosen[], int tot, int selected, int & maxi){
    if (x>N || selected==K){
        if (tot>maxi){
            maxi = tot;
            //for (int i=1; i<=N; i++) if (chosen[i]) cout<<value[i]<<' '; cout<<endl;
           // cout<<"tot: "<<selected<<' '<<tot<<endl;
        }
        return;
    }
    //not choose x
    dfs(x+1, chosen, tot, selected, maxi);
    //can choose x?
    bool can_choose = true;
    for (int i=1; i<x; i++){
        if (chosen[i] && react[i][x]){
            can_choose = false;
            break;
        }
    }
    //choose x
    if (can_choose){
        chosen[x] = true;
        dfs(x+1, chosen, tot+value[x], selected+1, maxi);
        chosen[x] = false;
    }
}

int main(){
    freopen("a.in","r", stdin);freopen("a.out","w",stdout);
    
    cin>>N>>K>>M;
    for (int i=1; i<=N; i++) cin>>value[i];
    memset(react, false, sizeof(react));
    while (M-->0){
        int x, y;
        cin>>x>>y;
        react[x][y] = react[y][x] = true;
    }
    bool chosen[21];
    memset(chosen, false, sizeof(chosen));
    int maxi = 0;
    dfs(1, chosen, 0, 0, maxi);
    cout<<maxi<<endl;
    
    return 0;  
}
