
#include "Time.h"
#include "iostream"
using namespace std;


Time::Time(){		//default constructor
	d_hour = 0;
	d_minutes = 0;
}
Time::Time(unsigned char h, unsigned char m):d_hour(wrappedHour(h,m)), d_minutes(m%60) {}

void Time::get(unsigned char &h, unsigned char &m) const{
	h = d_hour;
	m = d_minutes;
}

void Time::set(unsigned char h, unsigned char m){
	d_hour = wrappedHour(h, m);
	d_minutes = m % 60;
}

void Time::print(){
	cout << static_cast<int>(d_hour) << ":" << static_cast<int>(d_minutes);
}


unsigned char Time::wrappedHour(unsigned char wh, unsigned char wm) {
	int i = 0;
	if (wm >= 60) {
		int temp = wm;
		while (temp >= 60) {
			temp -= 60;
			i++;
		}
	}
	return (wh + i) % 24;
}