#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

struct Student {
  string first;
  string middle;
  string last;
  int age;
  bool female;
};

int main() {
  vector<string> names;
  string input, firstname;
  int count = 0;

  while(cin >> input) {
    if(count == 0) {
      firstname = input;
      count++;
    } else if(input != "#") {
      names.push_back(input);
    } else {
      string age_and_sex;
      cin >> age_and_sex;

      string lastname = names.back();
      stringstream middlename;
      names.pop_back();

      while(names.size() > 0) {
        middlename << " ";
        middlename << names.front();
        names.erase(names.begin());
      }

      char sex = age_and_sex.back();
      age_and_sex.pop_back();

      bool female;
      if(sex == 'M') {
        female = false;
      } else {
        female = true;
      }

      int age;
      age = atoi(age_and_sex.c_str());

      Student student = { firstname, middlename.str(), lastname, age, female };

      cout << student.first << student.middle << " " << student.last << " " << student.age << " " << student.female << endl;
      count = 0;
    }
  }


  return 0;
}
