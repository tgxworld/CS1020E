#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
  //  freopen("a.in","r",stdin); freopen("a.out","w",stdout);
    int N;
    cin>>N;
    set<string> incantations;
    incantations.clear();
    int tot_len = 0;
    while(N-->0){
        string str;
        cin>>str;
        if (incantations.find(str)==incantations.end()){
            tot_len += str.length();
            incantations.insert(str);
        }
    }
    cout<<tot_len<<endl;    
    return 0;
}
    
        
        
            
