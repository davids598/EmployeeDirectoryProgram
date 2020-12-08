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

bool operator > (const Date& a, const Date& b){
	if(a.y == b.y){	
		if(a.m == b.m){
			if(a.d == b.d) return false ;
			else if(a.d < b.d) return true ;
			else return false ;
		}
		else if(a.m < b.m) return true ;
		else return false ;
	}
	else if(a.y > b.y) return false ;
	else return true ;
}


#endif
