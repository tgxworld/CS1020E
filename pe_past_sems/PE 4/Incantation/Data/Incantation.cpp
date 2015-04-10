#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
char infile[]="incantationw.in";
char outfile[]="incantationw.out";
for (int tc=0; tc<10; tc++){
	infile[11]=outfile[11]='0'+tc;
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
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
}	
    return 0;
}
    
        
        
            
