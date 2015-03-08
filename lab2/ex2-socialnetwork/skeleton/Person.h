#ifndef person_h
#define person_h

#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Person{
private:
    string _name;
    vector<int> _groups; //contain the group id's of the person's groups.

public:
    Person();
    Person(string name);
    
    string getName();
    void joinGroup(int grp);
    void quitGroup(int grp);
    int getNumOfGroups();
    
    /*
    more
    */ 
};

#endif
