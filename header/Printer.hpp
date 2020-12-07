#ifndef __PRINTER_HPP__
#define __PRINTER_HPP__

#include <algorithm>

class Employee ;
class employeeDirectory ;

class Printer {
        public:
                virtual ~Printer() { }
                virtual void print(employeeDirectory* d) = 0 ;
} ;

class listPrint : public Printer {
        public:
		~listPrint() { }  ;
                virtual void print(employeeDirectory* d) ;       
} ;

class treePrint : public Printer {
        public:
                ~treePrint() { } ;
                virtual void print(employeeDirectory* d) ;
} ;

class sortDecorator : public Printer {
        public:
                sortDecorator(Printer* _p) { this->p = _p ; } ;
		virtual ~sortDecorator() { delete this->p ; }
                virtual void print(employeeDirectory* d) { this->p->print(d) ; } ;            
        private:
                Printer* p ;
} ;

class sortBySalary : public sortDecorator {
        public:
                sortBySalary(Printer* _p) : sortDecorator(_p) { }
                ~sortBySalary() { }
                virtual void print(employeeDirectory* d) ;
} ;

class sortByName : public sortDecorator{
        public:
                sortByName(Printer* _p) : sortDecorator(_p) { }
                ~sortByName() { } ;
                virtual void print(employeeDirectory* d) ;
} ;

class sortByHireDate : public sortDecorator{
        public:
                sortByHireDate(Printer* _p) : sortDecorator(_p) { }
                ~sortByHireDate() { } ;
                virtual void print(employeeDirectory* d) ;
} ;

class HighToLow : public sortDecorator{
        private:
                HighToLow(Printer* _p) : sortDecorator(_p) { }
                ~HighToLow() { } ;
                virtual void print(employeeDirectory* d) ;
} ;

#endif
