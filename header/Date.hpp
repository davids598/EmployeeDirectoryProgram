#ifndef DATE_HPP
#define DATE_HPP

#include <chrono>
#include <iostream>

using namespace std;

class Date {
        private:
                int m, d, y;
        public:
                Date(int month, int day, int year);
		friend ostream & operator << (ostream &out, const Date &_date) ;
};

#endif
