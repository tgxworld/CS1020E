#include <string>
#include <vector>

using namespace std;

class Person {
private:
  string _name;
  double _height, _weight;

  public:
    Person(string name, double height, double weight);
    static Person* tallest(vector<Person*> list);
    static Person* shortest(vector<Person*> list);
    string name();
    double getBMI();
};
