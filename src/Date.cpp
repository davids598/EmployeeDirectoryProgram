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

ostream & operator << (ostream &out, const Date &_date){
	out << _date.m << "/" << _date.d << "/" << _date.y ;
	return out ;
}

#endif
