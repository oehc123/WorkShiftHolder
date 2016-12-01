#ifndef TIME_H
#define TIME_H
#include <stdlib.h>

class Time {
	unsigned char d_hour;
	unsigned char d_minutes;
public:
	Time::Time();
	Time::Time(unsigned char, unsigned char);
	void Time::get(unsigned char& , unsigned char& ) const;
	void Time::set(unsigned char, unsigned char);
	void Time::print();
private:
	unsigned char Time::wrappedHour(unsigned char, unsigned char);
};

#endif