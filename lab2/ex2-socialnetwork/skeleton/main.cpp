/*
  
  
  You do not have to conform to the skeleton. You are free to design your own classes and methods.
*/

#include <iostream>
#include "SocialNetwork.h"
#include <vector>

int main(){
  int numOfOperations;
  cin >> numOfOperations;
  SocialNetwork socialNetwork;

  for(int i = 0; i < numOfOperations; ++i) {
    string operation;
    cin >> operation;

    if(operation == "Createjoin") {
      string personName, groupName;
      cin >> personName >> groupName;
      Group* group = socialNetwork.getGroup(groupName);
      Person* person = socialNetwork.getPerson(personName);
      
      if(group == NULL) {
        group = new Group(socialNetwork.getGroupSize() + 1, groupName);
        socialNetwork.addGroup(group);
      }

      if(person == NULL) {
        person = new Person(personName);
        socialNetwork.addPerson(person);
      }

      group->addMember(person); 
    }

    if(operation == "Quit") {
      string personName, groupName;
      cin >> personName >> groupName;
      Group* group = socialNetwork.getGroup(groupName);
      group->delMember(personName);
    }
  
    if(operation == "Query") {
      int queryType;
      cin >> queryType;
     
      if(queryType == 1) { 
        Group* group = socialNetwork.getLargestGroup();
        cout << group->getName() << endl;
      } else if(queryType == 2) {
        
      }
    }  
  }      
  return 0;
}
