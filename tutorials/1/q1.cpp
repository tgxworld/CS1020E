#include <iostream>
using namespace std;
enum DaysOfWeek { Mon, Tue, Wed, Thu, Fri, Sat, Sun };
string Days[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main() {
  string schedule = "";
  int day = Wed;
  int nextDay;

  do {
    if(day <= Fri) schedule += Days[day] + " ";
    nextDay = day++;

    switch(day % 7) {
      case Mon: nextDay -= 2;
      case Tue: nextDay += 3;
      case Wed: nextDay -= 20; break;
      case Thu: nextDay += 5;
      case Fri: nextDay += 7;
      default: nextDay = Sun + 7;
    };
    day = nextDay % 7;
  } while(nextDay >= 0);

  cout << "Schedule is: " << schedule << endl;
  return 0;
}
