#include "WorkWeek.h"
#include "iostream"

using namespace std;

WorkWeek::WorkWeek(int length):arrayLength(length), d_start(0), d_end(0), index(0){
	if (length != 0) {
		d_start = new Time[length];
		d_end = new Time[length];
	}
}
WorkWeek::WorkWeek(const WorkWeek& w):arrayLength(w.arrayLength), d_start(0), d_end(0), index(w.index) {
	d_start = new Time[arrayLength];
	d_end = new Time[arrayLength];
	for (int i = 0; i < index; i++) {
		d_start[i] = w.d_start[i];
		d_end[i] = w.d_end[i];
	}
}
void WorkWeek::addShift(unsigned char h, unsigned char m, unsigned int t) {
	Time start(h, m);
	Time end(h, m + t);
	if (index + 1 == arrayLength) {
		arrayLength = arrayLength * 2;
		Time *newStart = new Time[arrayLength];
		Time *newEnd = new Time[arrayLength];
		for (int i = 0; i < index; i++) {
			newStart[i] = d_start[i];
			newEnd[i] = d_end[i];
		}
		newStart[index] = start;
		newEnd[index] = end;
		delete d_start;
		delete d_end;
		d_start = newStart;
		d_end = newEnd;
	}
	else {
		d_start[index] = start;
		d_end[index] = end;
	}
	index++;
}

Time WorkWeek::getTotalHours() const {
	unsigned char startHour, endHour, startMinute, endMinute, totalMin, totalHour;
	totalMin = 0;
	totalHour = 0;
	for (int i =0; i < index; i++) {
		d_start[i].get(startHour, startMinute);
		d_end[i].get(endHour, endMinute);
		if (startHour == endHour) {
			totalMin += endMinute - startMinute;
			if (totalMin > 59) {
				totalMin = totalMin % 60;
				totalHour++;
			}
		}
		else {
			totalMin += 60 - startMinute;
			if (totalMin >= 60) {
				totalMin = totalMin % 60;
				totalHour++;
			}
			totalHour += (endHour - (startHour + 1));
		}
	//	cout << " entry " << i << " adds to " << static_cast<int>(totalHour)<< " "<< static_cast<int>(totalMin) << endl;
	}
	return Time(totalHour, totalMin);
}
void WorkWeek::toPrint() const {
	for (int i = 0; i < arrayLength; i++) {
		cout << "shift " << i << " from ";
		d_start[i].print();
		cout << " to ";
		d_end[i].print();
		cout<< "" << endl;
	}
}
WorkWeek::~WorkWeek(){
	if (arrayLength != 0) {
		delete d_start;
		delete d_end;
		cout << "this workweek has been deleted" << endl;
	}
}
