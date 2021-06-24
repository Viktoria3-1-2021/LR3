//Задание.Построение графиков в полярной системе координат

#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;
#define M_PI 3.14159265358979323846 //макрос, который представляет собой ассоциацию идентификатора или параметризованного идентификатора со строкой токена; 
class Polar
{
	double r; // радиус
	double phi; // угол
public:
	Polar operator + (Polar& p); // перегруженный оператор +
	Polar& operator += (Polar& p); // перегруженный оператор +=
	Polar operator - (Polar& p); // перегруженный оператор -
	Polar& operator -= (Polar& p); // перегруженный оператор -=
	Polar(const Polar& a);// Конструктор копирования
	Polar();// Конструктор по умолчанию
	Polar(double radius);// Конструктор из r
	Polar(double radius, double ygol);// Конструктор из r и phi
	double get_x();
	double get_r();
	double get_phi();
	double get_y();
	double distance(Polar& my);
	friend std::istream& operator >> (std::istream& in, Polar& r);// Перегруженные ввод и вывод
	friend std::ostream& operator << (std::ostream& out, const Polar& r);
};
Polar Polar::operator + (Polar& p)

{
	Polar temp(*this);
	temp += p;
	return temp;
}
Polar& Polar::operator += (Polar& p)

{
	double x = get_x() + p.get_x();
	double y = get_y() + p.get_y();
	r = sqrt(x * x + y * y);
	if (r == 0) { phi = 0; }
	if ((x > 0) && (y >= 0)) phi = atan(x / y);
	if ((x > 0) && (y < 0)) { phi = atan(x / y) + 2 * M_PI; }
	if ((x < 0) && (y < 0)) { phi = atan(x / y) + M_PI; }
	if ((x == 0) && (y > 0)) { phi = M_PI / 2; }
	if ((x == 0) && (y < 0)) { phi = (M_PI) / 2; }
	if ((x == 0) && (y == 0)) { phi = 0; }
	return *this;
}
Polar Polar::operator - (Polar& p)
{
	Polar temp(*this);
	temp -= p;
	return temp;
}
Polar& Polar::operator -= (Polar& p)
{
	double x = get_x() - p.get_x();
	double y = get_y() - p.get_y();
	r = sqrt(x * x + y * y);
	if (r == 0) { phi = 0; }
	if ((x > 0) && (y >= 0)) { phi = atan(x / y); }
	if ((x > 0) && (y < 0)) { phi = atan(x / y) + 2 * M_PI; }
	if ((x < 0) && (y < 0)) { phi = atan(x / y) + M_PI; }
	if ((x == 0) && (y > 0)) { phi = M_PI / 2; }
	if ((x == 0) && (y < 0)) { phi = (M_PI) / 2; }
	if ((x == 0) && (y == 0)) { phi = 0; }
	return *this;
}
Polar::Polar(const Polar& a)
{
	r = a.r; phi = a.phi;
}
Polar::Polar()
{
	r = 0; phi = 0;
}
Polar::Polar(double radius)
{
	r = radius; phi = 0;
}
Polar::Polar(double radius, double ygol)
{
	r = radius; phi = ygol;
}
double Polar::get_x()
{
	return r * cos(phi);
}
double Polar::get_y()
{
	return r * sin(phi);
}
double Polar::get_r()
{
	return r;
}
double Polar::get_phi()
{
	return phi;
}
double Polar::distance(Polar& my)
{
	return (sqrt((r * cos(phi) - my.r * cos(my.phi)) * (r * cos(phi) - my.r * cos(my.phi)) +
		(r * sin(phi) - my.r * sin(my.phi)) * (r * sin(phi) - my.r * sin(my.phi))));
}
istream& operator >> (istream& cin, Polar& r)
{
	cin >> r.r >> r.phi;
	return cin;
}
ostream& operator << (ostream& out, const Polar& r)
{
	out << r.r << " " << r.phi;
	return out;
}
int main(void)
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	for (float i(0); i < 500; i++) // ось X
	{
		SetPixel(hdc, 300, i, RGB(255, 255, 255));
	}
	for (float i(0); i < 700; i++) // ось Y
	{
		SetPixel(hdc, i, 250, RGB(255, 255, 255));
	}
	for (double i(0); i <= 2 * M_PI + 0.1; i += (M_PI / 8) * 0.0001)
	{
		Polar point(5 * sin(2 * i), i); // r, fi ///cюда вводится уранение
		SetPixel(hdc, 35 * point.get_x() + 300, -35 * point.get_y() + 250, RGB(255, 0, 0));
	}
	cin.ignore();
	system("pause");
	return 0;
}
