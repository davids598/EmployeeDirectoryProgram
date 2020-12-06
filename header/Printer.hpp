#ifndef __PRINTER_HPP__
#define __PRINTER_HPP__


class Employee ;
class employeeDirectory ;

class Printer {
        public:
                virtual void print(employeeDirectory* d) = 0 ;
                virtual ~Printer() {}  ;
} ;

class listPrint : public Printer {
        public:
                virtual void print(employeeDirectory* d) ;
                ~listPrint() { }  ;
} ;

class treePrint : public Printer {
        public:
                virtual void print(employeeDirectory* d) ;
                ~treePrint() { } ;
} ;

#endif
