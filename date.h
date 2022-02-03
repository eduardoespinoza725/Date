// ****************************************************************************************************************
// * Name: Eduardo Espinoza
// # Date: 1/21/22
// * Assignment: Assignment #2, Date Class
// * Description: Program will generate random lottery numbers using parameters entered by the user.
// ****************************************************************************************************************

#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

// Create a class called Date
class Date{

    // Array holds all the months of the year as strings
    const string MONTHS[13] {" ", "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};

    // These are the default values used for day, month, year, and format.
    static const int DEFAULT_MONTH = 1;
    static const int DEFAULT_DAY = 1;
    static const int DEFAULT_YEAR = 2000;
    static const char DEFAULT_FORMAT = 'D';

public:

    // Array holds all the total days in each individual month.
    int Days_in_Month[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // This is the default constructor, values are set to their default state.
    Date();

    // This constructor takes 4 parameters and stores them
    Date(int m, int d = DEFAULT_DAY, int y = DEFAULT_YEAR, char = DEFAULT_FORMAT);

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
    int GetMonth();

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
    int GetDay();

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
    int GetYear();

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
    int GetFormat();

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
    void SetMonth(int m);

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
    void SetDay(int d);

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
    void SetYear(int y);

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
    void SetFormat(char f);

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
    void Show();

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
    bool Set(int m, int d, int y);

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
    bool Check_For_Leap_Year(int y);

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
    void Input();

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
    int Compare(const Date &d);

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
    void Increment(int numDays = 1);

private:
    // These are the private member variables used in all Date objects
    int month;
    int day;
    int year;
    char format;
};


#endif
