#ifndef DATE_CPP
#define DATE_CPP

#include <chrono>
#include <iostream>
#include "../header/Date.hpp"

using namespace std;

Date::Date(int month, int day, int year){
        this->m = month;
        this->d = day;
        this->y = year;
}
ostream& Date::operator<<(ostream& os){
        os << this->m << "/" << this->d << "/" << this->y;
        return os;
}


#endif
