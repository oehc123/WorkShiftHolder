#include "Time.h"
#include "iostream"
#include "WorkWeek.h"
using namespace std;


void main() {
	WorkWeek w(2);
	w.addShift(1, 0, 60);
	w.addShift(2, 0, 120);
	w.addShift(3, 0, 30);
	w.addShift(3, 30, 15);
	w.addShift(4, 0, 45);
	w.toPrint();
	w.getTotalHours().print();
	

	
	/*
	unsigned char m;
	unsigned char h;
	t1.get(h, m);
	t1.set(24, 30);
	t1.get(h, m);
	cout << "Hello "<<static_cast<int>(h)<<" "<<static_cast<int>(m)  <<  endl;
	t1.print();
	*/
}