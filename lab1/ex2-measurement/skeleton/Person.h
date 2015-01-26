#include <string>
#include <vector>

using namespace std;

class Person {
	public:
		Person* tallest(vector<Person*> list);
		Person* shortest(vector<Person*> list);
		double getBMI();
};
