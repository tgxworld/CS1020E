#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Date
{
public:
  int day, month, year;

  Date(string date) {
    validate_date(date);
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(2, 2));
    year = stoi(date.substr(4, 4));
  };

private:
  int const DATE_LENGTH = 8;

  void validate_date(string date)
  {
    if(date.length() != DATE_LENGTH) {
      cout << "Invalid date received. Date must be in the following format: DDMMYYYY\n";
      exit(0);
    }
  }
};

class DateMagician
{
public:
  int get_num_of_days_between(Date start_date, Date end_date)
  {
    int num_of_days = calculate_days_difference(start_date, end_date);
    int num_of_days_between_years = calculate_num_of_days_between_years(start_date, end_date);
    return num_of_days + num_of_days_between_years;
  }

private:
  int calculate_days_difference(Date start_date, Date end_date)
  {
    unsigned int num_of_days = abs(calculate_num_of_days_to_start_of_year(start_date) - calculate_num_of_days_to_start_of_year(end_date));
    return num_of_days;
  }

  int calculate_num_of_days_to_start_of_year(Date date)
  {
    int total_days = 0;

    for(int month = date.month - 1; month >= 1; month--)
    {
      total_days += get_num_of_days_in_month(date);
    }

    total_days += date.day;
    return total_days;
  }

  int calculate_num_of_days_between_years(Date start_date, Date end_date)
  {
    int num_of_days = 0;
    int year_difference = end_date.year - start_date.year;

    num_of_days += year_difference * 365;

    for(int year = start_date.year; year <= end_date.year; year++)
    {
      if(leap_year(year))
      {
        if(year == start_date.year)
        {
          if(start_date.month < 2)
          {
            num_of_days += 1;
          }
        }
        else if(year == end_date.year)
        {
          if(end_date.month > 2)
          {
            num_of_days += 1;
          }
        }
        else
        {
          num_of_days += 1;
        }
      }
    }

    return abs(num_of_days);
  }

  bool leap_year(int year)
  {
    return ((year % 4) == 0);
  }

  int get_num_of_days_in_month(Date date)
  {
    switch(date.month)
    {
      case 1:
        return 31;
        break;
      case 2:
        // I'll handle leap years seperately
        return 28;
        break;
      case 3:
        return 31;
        break;
      case 4:
        return 30;
        break;
      case 5:
        return 31;
        break;
      case 6:
        return 30;
        break;
      case 7:
        return 31;
        break;
      case 8:
        return 31;
        break;
      case 9:
        return 30;
        break;
      case 10:
        return 31;
        break;
      case 11:
        return 30;
        break;
      case 12:
        return 31;
        break;
    }
  }
};

int main()
{
  string start, end;

  cout << "Please provide a start date (DDMMYYYY)\n";
  cin >> start;
  Date start_date(start);
  cout << "Please provide an end date (DDMMYYYY)\n";
  cin >> end;
  Date end_date(end);

  DateMagician date_magician;
  int num_of_days_between = date_magician.get_num_of_days_between(start_date, end_date);
  cout << "There are " << num_of_days_between << " days between " << start << " and " << end << endl;

  return 0;
};
