#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int main(){
    //freopen("a.in", "r",stdin);freopen("a.out", "w", stdout);
    int ans = 0;
    int N;
    cin>>N;
    int x, y, ins = 1;
    cin>>y;
    for (int i=1; i<N; i++){
        cin>>x;
        if (x>y) ins++;
        else {
			if (ins>ans) ans = ins;
			ins = 1;
		}
        y = x;
    }
    cout<<ans<<endl;
    return 0;
}
