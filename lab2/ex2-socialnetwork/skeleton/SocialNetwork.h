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
    vector <Group *> _groups;
    vector <Person *> _persons;

public:
    void addPerson(Person* person);
    void addGroup (Group* group);
    Group* getGroup(string name);
    Group* getGroupById(int id);
    Person* getPerson(string name);
    string answerQuery1();
    string answerQuery2();
    int getGroupSize();
    Group* getLargestGroup();  
    Person* getMostWellKnownDude();  
    /*
    more
    */          
};

#endif
