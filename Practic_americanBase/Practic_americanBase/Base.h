#pragma once


class Base {
protected:
	static int people_on_base;
	static int vehicles_on_base;
	static double petrol_on_base;
	static double goods_on_base;
};

int Base::people_on_base = 5000;
int Base::vehicles_on_base = 1500;
double Base::petrol_on_base = 20000.0; // in liters
double Base::goods_on_base = 50.0; // in tones