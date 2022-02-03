// ****************************************************************************************************************
// * Name: Eduardo Espinoza
// # Date: 1/28/22
// * Assignment: Assignment #2, Date Class
// * Description: Program creates a Date class and shows and formats the date in different ways.
// ****************************************************************************************************************

#include "date.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>
using namespace std;

// ***************************************************************************************************
// * Constructor: Date
// *
// * Description: This is the default constructor. It will assign month, day, year, and format to
// * their default values
// *
// * Parameter Description: This constructor has no parameters
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
Date::Date()
{
    SetMonth(DEFAULT_MONTH);
    SetDay(DEFAULT_DAY);
    SetYear(DEFAULT_YEAR);
    SetFormat(DEFAULT_FORMAT);
}

// ***************************************************************************************************
// * Constructor: Date
// *
// * Description: This constructor will take in values from the calling object and set them to month,
// * day, year, and format.
// *
// * Parameter Description: int m, int d, int y are values that are set to month, day, and year.
// * char f is a character that set to format
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
Date::Date(int m, int d, int y, char f)
{
    SetMonth(m);
    SetDay(d);
    SetYear(y);
    SetFormat(f);
}

// ***************************************************************************************************
// * Function: GetMonth
// *
// * Description: Returns the value of month to the calling object
// *
// * Parameter Description: This function has no parameters
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
int Date::GetMonth()
{
    return month;
}

// ***************************************************************************************************
// * Function: GetDay
// *
// * Description: Returns the value of day to the calling object
// *
// * Parameter Description: This function has no parameters
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
int Date::GetDay()
{
    return day;
}

// ***************************************************************************************************
// * Function: GetYear
// *
// * Description: Returns the value of year to the calling object
// *
// * Parameter Description: This function has no parameters
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
int Date::GetYear()
{
    return year;
}

// ***************************************************************************************************
// * Function: GetFormat
// *
// * Description: Returns the value of format to the calling object
// *
// * Parameter Description: This function has no parameters
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
int Date::GetFormat()
{
    return format;
}

// ***************************************************************************************************
// * Function: SetMonth
// *
// * Description: This function takes a value from the calling object and stores the value.
// *
// * Parameter Description: int m is the first value when a new Date object is created
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
void Date::SetMonth(int m)
{
    month = m;
}

// ***************************************************************************************************
// * Function: SetDay
// *
// * Description: This function takes a value from the calling object and stores the value.
// *
// * Parameter Description: int d is the second value when a new Date object is created
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
void Date::SetDay(int d)
{
    day = d;
}

// ***************************************************************************************************
// * Function: SetYear
// *
// * Description: This function takes a value from the calling object and stores the value.
// *
// * Parameter Description: int y is the third value when a new Date object is created
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
void Date::SetYear(int y)
{
    year = y;
}

// ***************************************************************************************************
// * Function: SetFormat
// *
// * Description: This function takes a value from the calling object and stores the value.
// *
// * Parameter Description: char f is the fourth and final value when a new Date object is created
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Code given by Dr. David A. Gaitros
// ***************************************************************************************************
void Date::SetFormat(char f)
{
    format = f;
}

// ***************************************************************************************************
// * Function: Show
// *
// * Description: This function first, checks if the values stored in month, day, and year are valid.
// * If the values are not valid, will set them to their default values.
// * Second, checks if the year stored is a leap year by calling another function and if Feb has 29
// * days or 28 days. Finally, the function will display the calling object's values and display them
// * according to the value stored in format.
// *
// * Parameter Description: none
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Idea given by Dr. David A. Gaitros. Idea for calculating Julian date given
// * Dr. David A. Gaitros
// ***************************************************************************************************
void Date::Show()
{
    // Code will check if user entered a value 1-12, if not will set it to the default value
    if(month > 12 || month < 1)
    {
        month = DEFAULT_MONTH;
    }

    // Check if the user entered a leap year
    bool leap = Check_For_Leap_Year(year);

    // If the values entered are a leap year, 2, and 29 if all true will set day to 29.
    if(leap == 1 && month == 2 && day == 29)
    {
        day = 29;
    }

        // If the values entered were not a leap year , 2, and 29, if all true will set day to its default value.
    else if(leap == 0 && month == 2 && day == 29)
    {
        day = DEFAULT_DAY;
    }

        // Else if will compare day to the total number of day in a month stored in an array or if day is less than 1.
    else if(day > Days_in_Month[month] || day < 1)
    {
        // if day is larger than the number of days in a month or less than 1, will set day to its default value.
        day = DEFAULT_DAY;
    }

    // If the value stored for year is less than 1582, will set the value of year to its default value.
    if(year < 1582)
    {
        year = DEFAULT_YEAR;
    }

    // If the value of format is D or d, will display in M/D/YYYY format
    if(format == 'D' || format == 'd')
    {
        cout << month << " " << day << " " << year << endl;
    }

        // If the value of format is T or t, will display in MM/DD/YY format
    else if(format == 'T' || format == 't')
    {

        // If will check if the values for month and day are less than 10. If they are, will add a 0 to the front of both of them.
        if(month < 10 && day < 10)
        {
            // The value of year is converted to a string and only displays the last two digits.
            cout <<  0 << month << " " << 0 << day << " " << to_string(year)[2] << to_string(year)[3] << endl;
        }

            // If will check if the value of month is less than 10. If it is, will add a 0 to the front of it.
        else if(month < 10)
        {
            // The value of year is converted to a string and only displays the last two digits.
            cout <<  0 << month << " " << day << " " << to_string(year)[2] << to_string(year)[3] << endl;
        }

            // If will check if the value of day is less than 10. If it is, will add a 0 to the front of it.
        else if(day < 10)
        {
            // The value of year is converted to a string and only displays the last two digits.
            cout  << month << " " << 0 << day << " " << to_string(year)[2] << to_string(year)[3] << endl;
        }

            // Else will simply display the values as they are.
        else
        {
            // The value of year is converted to a string and only displays the last two digits.
            cout << month << " " << day << " " << to_string(year)[2] << to_string(year)[3] << endl;
        }
    }

        // If the value of format is L or l, will in MONTH/D/YYYY format.
    else if(format == 'L' || format == 'l')
    {
        // The value of month is used to print out the correct month in the correct index.
        cout << MONTHS[month] << " " << day << " " << year << endl;
    }

        // If the value of format is J or j, will display in Julian date format DDD/YYYY.
    else if(format == 'J' || format == 'j')
    {
        // Check to see if the value for year is a leap year, the year will have a total of 366 days.
        bool leapyear = Check_For_Leap_Year(year);

        // If will take into account the days after a leap day. Everyday after the leap year incremented by 1
        if(leapyear == 1 && month >= 2)
        {
            int jdate = 1;
            // Loop adds all the values stored in the array Days_in_Month and assigns it to jdate.
            for(int i = 0; i <= month; i++)
            {
                jdate += Days_in_Month[i];
            }

            // The difference between the total days in the month and the value of day, is stored in jdate.
            jdate -= Days_in_Month[month] - day;

            // If takes into account everyday before the Feb 29 and subtracts 1 from them. These dates will always stay the same.
            if(month <= 2 && day <= 29)
            {
                // Days before the Feb 29 are printed out.
                cout << jdate - 1 << " " << year << endl;
            }
            else
            {
                // The date is printed out.
                cout << jdate << " " << year << endl;
            }
        }

            // Else is executed when it is not a leap year, the year will have a total of 365 days.
        else
        {
            int jdate = 0;
            // Loop adds all the values stored in the array Days_in_Month and assigns it to jdate.
            for(int i = 0; i <= month; i++)
            {
                jdate += Days_in_Month[i];
            }
            // The difference between the total days in the month and the value of day, is stored in jdate.
            jdate -= Days_in_Month[month] - day;

            // The date is printed out.
            cout << jdate << " " << year << endl;
        }
    }
}

// ***************************************************************************************************
// * Function: Set
// *
// * Description: This function will take into account leap years. The function valid dates the
// * values entered in by the calling object. If any of the values are invalid, the function will
// * immediately exit.
// *
// * Parameter Description: int m, int d, int y are values passed by the calling object. Each value
// * is checked if they are within the Gregorian calendar.
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Idea given by Dr. David A. Gaitros.
// ***************************************************************************************************
bool Date::Set(int m, int d, int y)
{
    //
    bool validdate = true;

    // The value of m is checked to see if it is greater than 1 or less than 1.
    if(m > 12 || m < 1)
    {
        // Invalid, the program will return false and exit the function.
        return false;
    }

    // The value of y is checked if it is a leap year.
    bool leap = Check_For_Leap_Year(y);

    // If checks if the value for year is a leap year and if the value for m is 2 and d is 29.
    if(leap == 1 && m == 2 && d == 29)
    {
        validdate = true;
    }

        // If the value of y was not a leap year, and the value for m is 2 and d is 29.
    else if(leap == 0 && m == 2 && d == 29)
    {
        // Invalid, the program will return false and exit the function.
        return false;
    }

        // If the value of d is greater than the days in m or if d is less than one.
    else if(d > Days_in_Month[m] || d < 1)
    {
        // Invalid, the program will return false and exit the function.
        return false;
    }

    // If the value of y is less than 1582.
    if(y < 1582)
    {
        // Invalid, the program will return false and exit the function.
        return false;
    }

    // If the program never returned false, the function will return true to the calling object.
    return validdate;
}

// ***************************************************************************************************
// * Function: Check_For_Leap_Year
// *
// * Description: This function checks the value of y and uses an algorithm to check if it is a
// * proper leap year. A leap year is a year that is first divisible by 4, then divisible by 100.
// * Centuries that are in the form xx00, are only leap years if they are divisible by 400.
// *
// * Parameter Description: int y is the value of year.
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Idea given by Dr. David A. Gaitros.
// * Algorithm to find leap year from https://docs.microsoft.com/en-us/office/troubleshoot/excel/determine-a-leap-year
// ***************************************************************************************************
bool Date::Check_For_Leap_Year(int y)
{
    bool isitaleapyear;

    // A leap year is divisible by 4.
    if(y % 4 == 0)
    {
        isitaleapyear = true;

        // A leap year is also divisible by 100 but must also be divisible by 400.
        if(y % 100 == 0)
        {
            if(y % 400 == 0)
            {
                isitaleapyear = true;
            }
                // If not a leap year, return false and exit the function.
            else
                return false;
        }
    }

        // If not a leap year, return false and exit the function.
    else
        return false;

    // Return true back to the function call.
    return isitaleapyear;
}

// ***************************************************************************************************
// * Function: Input
// *
// * Description: This function ask the user for input. The input will be read in using sscanf.
// * The values entered by the user will be read in the form m/d/yyyy. The function will also
// * check if the values entered are a leap year and if they are a valid date. If the user entered an
// * invalid date, they will be prompted to re-enter a new date. If the user enters an invalid date
// * again, the function will exit and all the values will keep their default values.
// *
// * Parameter: none
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Idea given by Dr. David A. Gaitros. sscanf code provide by Dr Gaitros
// ***************************************************************************************************
void Date::Input()
{
    string instring;

    // The function will ask the user to input a date in the form M/D/YYYY
    cout << "Enter any date in the format M/D/YYYY: ";
    getline(cin, instring);
    // sscanf will read in the user input and assign the values to month, day, and year
    sscanf(instring.c_str(), "%d/%d/%d", &month, &day, &year);

    // Users input will be checked if it is a leap year
    bool leap = Check_For_Leap_Year(year);

    // If the user entered a valid leap year, 2, and 29, day is set to 29.
    if(leap == 1 && month == 2 && day == 29)
    {
        day = 29;
    }

        // If the user entered an invalid leap year, they will be prompted to re-enter a valid date
    else if(leap == 0 && month == 2 && day == 29)
    {
        cout << "Not a leap year" << endl;
        cout << "Try again: ";
        getline(cin, instring);
        sscanf(instring.c_str(), "%d/%d/%d", &month, &day, &year);
    }

        // If the user entered any value that is invalid, they will be prompted to re-enter a valid date
    else if((month > 12 || month < 1 || day > Days_in_Month[month] || day < 1 || year < 1582) && leap == 0)
    {
        cout << "Invalid date" << endl;
        cout << "Try again: ";
        getline(cin, instring);
        sscanf(instring.c_str(), "%d/%d/%d", &month, &day, &year);

    }
}

// ***************************************************************************************************
// * Function: Compare
// *
// * Description: This function will compare 2 dates and will return a value based on which one was
// * earlier, which one is later, or if they are the same.
// *
// * Parameter: const Date &d is an object and its d value passed by reference. The calling object
// * is compared to the object passed as an argument.
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Idea given by Dr. David A. Gaitros. Calculations provide by Dr Gaitros
// ***************************************************************************************************
int Date::Compare(const Date &d)
{
    // The values for the Date object in the parameter are converted to a single integer
    int date1 = d.year * 1000 + d.month * 100 + d.day;
    // The values for the calling object are converted to a single integer
    int date2 = year * 1000 + month * 100 + day;

    // If date1, the parameter object, is greater than date2, the function will display a -1
    if(date1 > date2)
    {
        // The calling object comes first chronologically.
        return -1;
    }

        // If date1, the parameter object, is less than date2, the function will display a 1
    else if(date1 < date2)
    {
        // The parameter object comes first chronologically.
        return 1;
    }
        // If both dates are the same, display 0.
    else
        return 0;
}

// ***************************************************************************************************
// * Function: Increment
// *
// * Description: This function will increment a date and adjust it accordingly, while also taking
// * into account leap years. This function has a default increment of 1.
// *
// * Parameter: int numDays is set to a default of one. The user can change this number.
// *
// * Date: 01/28/2022
// * Author: Eduardo Espinoza
// * References: Idea given by Dr. David A. Gaitros.
// ***************************************************************************************************
void Date::Increment(int numDays)
{
    // This loop will count and increment based on the value of numDays.
    for(int i = 0; i < numDays; i++)
    {
        // The value of year will is checked if it is a valid leap year.
        bool leapyear = Check_For_Leap_Year(year);

        // If the year is a valid leap year, increment by 1.
        if(leapyear == 1)
        {
            day++;

            // After the value of day is incremented, if will check if day and month are 2 and 29.
            if(day == 29 && month == 2)
            {
                // set day to 29
                day = 29;
            }

                // If the values were not 2 and 29 and if day is larger than the days of its month.
            else if(day > Days_in_Month[month])
            {
                // Day is set to 1 and 1 is added to the value of month.
                day = 1;
                month += 1;
            }

            // After adding 1 to the value of month, check if the value is larger than 12.
            if(month > 12)
            {
                // Month is set to 1 and 1 is added to the value of year.
                month = 1;
                year += 1;
            }
        }

            // Else statement will execute if the user did not enter a leap year
        else
        {
            // Increment the value of day by 1.
            day++;

            // If day is larger than the total days of its month.
            if(day > Days_in_Month[month])
            {
                // Day is set to 1 and 1 is added to the value of month.
                day = 1;
                month += 1;
            }

            // After adding 1 to the value of month, check if the value is larger than 12.
            if(month > 12)
            {
                // Month is set to 1 and 1 is added to the value of year.
                month = 1;
                year += 1;
            }
        }
    }
}
