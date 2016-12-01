#ifndef WORKWEEK_H
#define WORKWEEK_H
#include "Time.h"

class WorkWeek
{
	Time *d_start;
	Time *d_end;
	int arrayLength;
	int index;

public:
	WorkWeek(int);
	WorkWeek(const WorkWeek& w);
	void addShift(unsigned char, unsigned char, unsigned int);
	void toPrint() const;
	Time getTotalHours() const;
	~WorkWeek();
};

#endif