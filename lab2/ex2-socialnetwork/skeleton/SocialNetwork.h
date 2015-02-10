#ifndef social_network_h
#define social_network_h

#include <cstdlib>
#include <cstring>
#include <vector>
#include "Person.h"
#include "Group.h"
using namespace std;

class SocialNetwork{
private:
    vector <Group *> groups;
    vector <Person *> persons;

public:
    SocialNetwork();
    
    Person * addPerson(string name);
    Group * addGroup (string name);
    string answerQuery1();
    string answerQuery2();    
    /*
    more
    */          
};

#endif
