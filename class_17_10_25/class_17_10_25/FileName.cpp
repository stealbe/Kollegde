#include <iostream>
using namespace std;

class Student
{
private:
	double points[10];
public:
	Student()
	{
		for (size_t i = 0; i < 10; i++)
		{
			points[i] = 0;
		}
	}
	void Init()
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << "Point " << i + 1 << ": ";
			cin >> points[i];
		}
	}
	void Print()
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << "Point " << i + 1 << ": " << points[i] << endl;
		}
	}
	void Edit(double n, int i)
	{
		if (n <= 0) return;
		points[i] = n;
	}
	double MPoint()
	{
		double sum = 0;
		for (size_t i = 0; i < 10; i++)
		{
			sum += points[i];
		}
		return sum / 10;
	}
};

int main() {
	int iSwitch = 0;
	Student st;
	do
	{
		cout << "1 - print, 2 - Edit at, 3 - isPass" << endl;
		cin >> iSwitch;
		switch (iSwitch)
		{
		case 1:
			st.Print();
			break;
		case 2:
			int i;
			cout << "Choose 1-10 point: " << endl;
			cin >> i;
			cout << "Enter point: " << endl;
			double point;
			cin >> point;
			st.Edit(point, i - 1);
			break;
		case 3:
			bool isPass = st.MPoint() >= 10.7;
			cout << isPass << endl;
			break;
		default:
			iSwitch = 0;
			break;
		}
	} while (iSwitch != 0);
    return 0;
}