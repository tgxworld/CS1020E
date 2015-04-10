#include <iostream>
using namespace std;

int N, M;
int strength[21];
bool conflict[21][21];

void dfs(int x, bool chosen[], int tot, int & maxi, int &cnt){
    if (x>N){
        if (tot>maxi){
            maxi = tot;
            cnt = 1;
        }
        else if (tot==maxi) cnt++;
        return;
    }
    //not choose x
    dfs(x+1, chosen, tot, maxi, cnt);
    //can choose x?
    bool can_choose = true;
    for (int i=1; i<x; i++){
        if (chosen[i] && conflict[i][x]){
            can_choose = false;
            break;
        }
    }
    //choose x
    if (can_choose){
        chosen[x] = true;
        dfs(x+1, chosen, tot+strength[x], maxi, cnt);
        chosen[x] = false;
    }
}

int main(){
    freopen("a.in","r", stdin);freopen("a.out","w",stdout);
    
    cin>>N>>M;
    for (int i=1; i<=N; i++) cin>>strength[i];
    memset(conflict, false, sizeof(conflict));
    while (M-->0){
        int x, y;
        cin>>x>>y;
        conflict[x][y] = conflict[y][x] = true;
    }
    bool chosen[21];
    memset(chosen, false, sizeof(chosen));
    int maxi = 0;
    int cnt = 0;
    dfs(1, chosen, 0, maxi, cnt);
    cout<<maxi<<endl;
    cout<<cnt<<endl;
    
    return 0;  
}
