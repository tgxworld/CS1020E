#include <iostream>
using namespace std;

void printBlurb()
{
  cout << " day of Christmas" << endl << "My true love sent to me:" << endl;
}

int main()
{
  for (day = 1; day < 13; day++) {
    cout << "On the ";

    switch (day)
    {
      case 1:
        cout << "first ";
        printBlurb();
        cout << "a partridge in a pear tree" << endl;
        break;
      case 2:
        cout << "second ";
        cout << "two turtle doves" << endl << "and ";
        printBlurb();
        break;
      case 3:
        cout << "third ";
        printBlurb();
        break;
      case 4:
        cout << "fourth ";
        printBlurb();
        break;
      case 5:
        cout << "fifth ";
        printBlurb();
        break;
      case 6:
        cout << "sixth ";
        printBlurb();
        break;
      case 7:
        cout << "seventh";
        printBlurb();
        break;
      case 8:
        cout << "eighth ";
        printBlurb();
        break;
      case 9:
        cout << "ninth ";
        printBlurb();
        break;
      case 10:
        cout << "tenth ";
        printBlurb();
        break;
      case 11:
        cout << "eleventh ";
        printBlurb();
        break;
      case 12:
        cout << "twelfth ";
        printBlurb();
        break;
    }

    switch (day)
    {
      case 12:
        cout << "twelve drummers drumming" << endl;
      case 11:
        cout << "eleven pipers piping" << endl;
      case 10:
        cout << "ten lords a leaping" << endl;
      case 9:
        cout << "nine ladies dancing" << endl;
      case 8:
        cout << "eight maids a milking" << endl;
      case 7:
        cout << "seven swans a swimming" << endl;
      case 6:
        cout << "six geese a laying" << endl;
      case 5:
        cout << "five golden rings " << endl;
      case 4:
        cout << "four calling birds" << endl;
      case 3:
        cout << "three french hens" << endl;
      case 2:
      case 1:
    }
  }

  return 0;
};
