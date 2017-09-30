/*
This is my first library. This class describe long int and can work with very long numbers.
Today 30.09.2017 and today my class comlpleted.
All rights reserved by Goldnotch
*/

#pragma once
#include <iostream>
using namespace std;

#define ull unsigned long long
#define ON_NEW_LINE (int)1//ПЕРЕХОД НА НОВУЮ СТРОКУ

class LongInt
{
public:
	LongInt(); //конструктор
	~LongInt(); //деструктор

	//Математические функции
	friend LongInt ABS(LongInt &num);//Модуль числа
	friend LongInt POW(LongInt &a, ull n);//возведение в степень
	friend LongInt GCD(LongInt &a, LongInt &b);

	//Логические операторы с LongInt
	bool operator==(LongInt &num);//логическое равно
	bool operator>(LongInt& num);//строго больше
	bool operator<(LongInt& num);//строго меньше
	bool operator>=(LongInt& num);//больше или равно
	bool operator<=(LongInt& num);//больше или равно
	bool operator!=(LongInt &num);//не равно

	//Логические операторы с long long и прочее
	bool operator==(long long num);//логическое равно
	bool operator>(long long num);//строго больше
	bool operator<(long long num);//строго меньше
	bool operator>=(long long num);//больше или равно
	bool operator<=(long long num);//больше или равно
	bool operator!=(long long num);//не равно

	//Арифметические операторы
	void operator= (LongInt &num);//присваивание
	friend LongInt operator+(LongInt &a, LongInt &b);//Сложение двух чисел
	friend LongInt operator-(LongInt &a, LongInt &b);//Вычитание двух чисел
	friend LongInt operator*(LongInt &a, LongInt &b);//Умножение двух чисел
	//Арифметические операции с числами типа long long(int, short и т.д.)
	friend LongInt operator+(LongInt &a, long long b);//сложение с числом
	friend LongInt operator-(LongInt &a, long long b);//вычитание с числом
	friend LongInt operator*(LongInt &a, long long b);//умножение с числом
	//не хочу делать целочисленное деление


	//input/output
	void Show(const int OnNewLine = 0);//DEBUG функция. Заменить на потоковый ввод/вывод
	void operator << (const char* num);//ввод из строки (используем для очень длинных чисел)
	void operator << (const long long num); // ввод из числа
	

private:
	short *digit;//цифра
	ull size;//размер
	bool sign;	//знак true - минус, false = +
	bool resize(ull count);//функция изменения размера числа. Убирает цифры слева от числа. 364367.resize(2) = 67

};


/*
This is my first library. This class describe long int and can work with very long numbers.
Today 30.09.2017 and today my class comlpleted.
All rights reserved by Goldnotch
*/