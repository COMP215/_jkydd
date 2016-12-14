#include <iostream>
#include <string>
#include <array>

using namespace std;

//Doomsday Algorithm
//Calculate what day of the week any given date is dynamically without a calender
int main()
{
    //input
    int month, day, year;
    cout << "Enter a date MM/DD/YYYY" << endl;
    cout << "Month:";
    cin >> month;
    //month = 9;
    cout << "Day:";
    cin >> day;
    //day = 7;
    cout << "Year:";
    cin >> year;
    //year = 1978;
    //find doomsday of the year
    int cal1, cal2, cal3, cal4, total, doomsday;
    cal1 = (year%100)/12;
    cal2 = (year%100)-(cal1*12);
    cal3 = cal2/4;
    /*centuries anchor day
    1800 - 1899: Friday or 5
    1900 - 1999: Wednesday or 3
    2000 - 2099: Tuesday or 2
    2100 - 2199: Sunday or 0*/
    if (1800 < year && year < 1899){
        cal4 = 5;
    }
    if (1900 < year && year < 1999){
        cal4 = 3;
    }
    if (2000 < year && year < 2099){
        cal4 = 2;
    }
    if (2100 < year && year < 2199){
        cal4 = 0;
    }
    total = cal1+cal2+cal3+cal4;
    doomsday = total%7;
    array <string,7> days = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    //the doomsday of the year
    cout << "Doomsday:" << days[doomsday] << endl;

    //now find the dates day of the week in relation to the dooms day
    array <int,12> monthDoomsdays = {3,7,7,4,2,6,4,1,5,3,7,5};
    array <int,12> monthDoomsdaysLeap = {4,1,7,4,2,6,4,1,5,3,7,5};
    int finalday;
    if (year%4 == 0 && year%100 == 0){
        finalday = (doomsday+((day - monthDoomsdaysLeap[month-1])%7))%7;
    }else{
        finalday = (doomsday+((day - monthDoomsdays[month-1])%7))%7;
    }
    cout << "that date is a " << days[finalday] << endl;
}
