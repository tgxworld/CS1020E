#include "SocialNetwork.h"
#include <set>

Group* SocialNetwork::getGroup(string name) {
  for(vector<Group*>::iterator iter = this->_groups.begin(); iter < this->_groups.end(); ++iter) {
    if(name == (*iter)->getName()) {
      return *iter;
    }
  }

  return NULL;
}

Group* SocialNetwork::getGroupById(int id) {
  for(vector<Group*>::iterator iter = this->_groups.begin(); iter < this->_groups.end(); ++iter) {
    if(name == (*iter)->getId()) {
      return *iter;
    }
  }

  return NULL;
}

void SocialNetwork::addGroup(Group* group) {
  this->_groups.push_back(group); 
}

int SocialNetwork::getGroupSize() {
  return this->_groups.size();
}

Person* SocialNetwork::getPerson(string name) {
  for(vector<Person*>::iterator iter = this->_persons.begin(); iter < this->_persons.end(); ++iter) {
    if(name == (*iter)->getName()) {
      return *iter;
    }
  }

  return NULL;
}

void SocialNetwork::addPerson(Person* person) {
  this->_persons.push_back(person);
}

Group* SocialNetwork::getLargestGroup() {
  Group* largestGroup = this->_groups.front();

  for(vector<Group*>::iterator iter = this->_groups.begin() + 1; iter < this->_groups.end(); ++iter) {
    if((*iter)->getNumOfMembers() > largestGroup->getNumOfMembers()) {
      largestGroup = (*iter);
    } else if((*iter)->getNumOfMembers() == largestGroup->getNumOfMembers()) {
      if((*iter)->getName() < largestGroup->getName()) {
        largestGroup = (*iter);
      }
    }
  }

  return largestGroup;
}

Person* SocialNetwork::getMostWellKnownDude() {
  Person* wellKnown = NULL;

  for(vector<Person*>::iterator iter = this->_persons.begin(); iter < this->_persons.end(); ++iter) {
    vector<Groups*> groups = p
  } 
}
