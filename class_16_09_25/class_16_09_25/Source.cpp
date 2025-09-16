#include <iostream>
using namespace std;

class Car
{
private:
	char* model;
	char* country;
	char* color;
	int year;
	double price;
public:
	Car()
	{
		model = nullptr;
		country = nullptr;
		color = nullptr;
		year = 0;
		price = 0;
	}
	//Car(const char* imodel)
	//{
	//	SetModel(imodel);
	//}
	//Car(const char* imodel, const char* icountry)
	//{
	//	SetModel(imodel);
	//	SetCon(icountry);
	//}
	//Car(const char* imodel, const char* icountry, const char* icolor)
	//{
	//	SetModel(imodel);
	//	SetCon(icountry);
	//	SetCol(icolor);
	//}
	//Car(const char* imodel, const char* icountry, const char* icolor, int iyear)
	//{
	//	SetModel(imodel);
	//	SetCon(icountry);
	//	SetCol(icolor);
	//	SetYear(iyear);
	//}
	Car(const char* imodel, const char* icountry, const char* icolor, int iyear, double iprice)
	{
		SetModel(imodel);
		SetCon(icountry);
		SetCol(icolor);
		SetYear(iyear);
		SetPrice(iprice);
	}
	Car(const Car& obj)
	{
		model = new char[strlen(obj.model) + 1];
		strcpy_s(model, strlen(obj.model), obj.model);
		country = new char[strlen(obj.country) + 1];
		strcpy_s(country, strlen(obj.country), obj.country);
		color = new char[strlen(obj.color) + 1];
		strcpy_s(color, strlen(obj.color), obj.color);
		price = obj.price;
		year = obj.year;
	}
	void SetModel(const char* imodel)
	{
		if (model != nullptr) delete[] model;
		model = new char[strlen(imodel) + 1];
		if (imodel != nullptr) strcpy_s(model, strlen(imodel) + 1, imodel);
	}
	void SetCon(const char* icountry)
	{
		if (country != nullptr) delete[] country;
		country = new char[strlen(icountry) + 1];
		if (icountry != nullptr) strcpy_s(country, strlen(icountry) + 1, icountry);
	}
	void SetCol(const char* icolor)
	{
		if (color != nullptr) delete[] color;
		color = new char[strlen(icolor) + 1];
		if (icolor != nullptr) strcpy_s(color, strlen(icolor) + 1, icolor);
	}
	void SetYear(int iyear)
	{
		if (iyear > 1800) year = iyear;
	}
	void SetPrice(double iprice)
	{
		if (iprice >= 0) price = iprice;
	}
	void Enter()
	{
		cout << "Model: ";
		char* imodel = nullptr;
		cin >> imodel;
		SetModel(imodel);
		cout << "Country: ";
		char* icountry = nullptr;
		cin >> icountry;
		SetCon(icountry);
		cout << "Color: ";
		char* icolor = nullptr;
		cin >> icolor;
		SetCol(icolor);
		int iyear;
		do
		{
			cout << "Year: ";
			cin >> iyear;
		} while (iyear > 1800);
		SetYear(iyear);
		double iprice;
		do
		{
			cout << "Price: ";
			cin >> iprice;
		} while (iprice >= 0);
		SetPrice(iprice);
	}
	void Print()
	{
		cout << "Model: ";
		model != nullptr ? cout << model << endl : cout << "None" << endl;
		cout << "Country: ";
		country != nullptr ? cout << country << endl : cout << "None" << endl;
		cout << "Model: ";
		color != nullptr ? cout << color << endl : cout << "None" << endl;
		cout << "Year: ";
		year > 1800 ? cout << year << endl : cout << "None" << endl;
		cout << "Price: ";
		price > 0 ? cout << price << endl : cout << "Free" << endl;
	}
	~Car()
	{
		delete[] model;
		delete[] country;
		delete[] color;
	}
};

int main()
{
	Car Q7;
	Q7.Enter();
	Q7.Print();
}