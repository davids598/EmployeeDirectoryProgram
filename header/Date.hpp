#ifndef DATE_HPP
#define DATE_HPP

#include <chrono>
#include <iostream>

using namespace std;

class Date {
        private:
                int m, d, y;
        public:
		Date() { this-> m = 0 ; this->d = 0 ; this->y = 0 ; }
                Date(int month, int day, int year);
		friend bool operator > (const Date& a, const Date& b) ;
		friend ostream & operator << (ostream &out, const Date &_date) ;
};

#endif
