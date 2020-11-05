#include <iostream>
using namespace std;

class Time
{
public:
	Time();
	void setTime(int, int, int); //установка часов, минут, секунд
	void printMilitary();//печать времени в военном формате
	void printStandart();//печать времени в стандартном формате
private:
	int hour; //0-23
	int minute;//0-59
	int second;//0-59

};

//Конструктор Time присваивает нулевые начальные значения каждому элементу
//данных.Обеспечивает согласованое начальное состояние всех объектов 
//Time

Time::Time() {hour = minute = second = 0; }
//Задание нового значения Time в виде военного времени.
//Проверка правильности значений данных.
//Обнуление неверных значений.
void Time::setTime(int h, int m, int s) 
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}
//Печать времени в военном формате
void Time::printMilitary()
{
	cout << (hour < 1 ? "0" : "") << hour << ":" << (minute < 1 ? "0" : "") << minute <<
		":" << (second < 1 ? "0" : "") << second;
}
//Печать времени в стандартном формате
void Time::printStandart()
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << (minute < 1 ? "0"
		: "") << minute << ":" << (second < 1 ? "0" : "") << second << (hour < 12 ? " AM" : " PM");
}
//Формирование проверки простого класса Time
int main()
{
	Time t;
	cout << "Начальное значение военного времени равно ";
	t.printMilitary();
	cout << endl << "Начальне значение стандартного времени равно ";
	t.printStandart();
	t.setTime(13, 27, 6);
	cout << endl << endl << "Военное время после set.Time равно ";
	t.printMilitary();
	cout << endl << "Сатндартное время после set.Time равно ";
	t.printStandart();
	t.setTime(99, 99, 99);//попытка установить неверные значения
	cout << endl << endl << "После попытки неправильной установки: " << endl << "Военное время: ";
	t.printMilitary();
	cout << endl << "Стандартное время: ";
	t.printStandart();
	cout << endl;
	return 0;

}