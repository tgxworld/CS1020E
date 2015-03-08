#ifndef group_h
#define group_h

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

class Group{
private:
    int _id; // assign a unique id to each group.
    string _name;
    vector <Person *> _members;

public:
    Group();
    Group(int id, string name);
    
    int getId();
    string getName();    
    void addMember(Person *p);
    void delMember(string name);    
    int getNumOfMembers();
    /*
    more
    */ 
};


#endif
