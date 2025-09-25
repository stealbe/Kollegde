class Reservior
{
	char* name;
	double width;
	double length;
	double deph;

public:
	Reservior();
	Reservior(char* _name, double _w, double _l, double _d);
	Reservior(Reservior& obj);
	~Reservior();
	
	double Capacity() const;
	double Square() const;
	bool Test(const char* type) const;
	bool Test_square(Reservior& obj) const;
	void Copy(const Reservior& obj);
};
