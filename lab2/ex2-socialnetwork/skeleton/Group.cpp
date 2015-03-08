#include "Group.h"

Group::Group(int id, string name) {
  this->_id = id;
  this->_name = name;
}

int Group::getId() {
  return this->_id;
}

string Group::getName() {
  return this->_name;
}

int Group::getNumOfMembers() {
  return  this->_members.size();
}

void Group::addMember(Person* p) {
  this->_members.push_back(p);
}

void Group::delMember(string name) {
  for(vector<Person*>::iterator iter = this->_members.begin(); iter < this->_members.end(); ++iter) {
    if((*iter)->getName() == name) {
      this->_members.erase(iter);
    }
  }
}
