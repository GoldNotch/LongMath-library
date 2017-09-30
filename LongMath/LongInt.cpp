/*
This is my first library. This class describe long int and can work with very long numbers.
Today 30.09.2017 and today my class comlpleted.
All rights reserved by Goldnotch
*/

#include "LongInt.h"

LongInt::LongInt()
{
	size = 1;
	digit = new short[size];
	digit[0] = 0;
	sign = false;
}

LongInt::~LongInt()
{
	delete[]digit;
}

bool LongInt::operator==(LongInt &num)
{
	bool isEqual(true);
	//есди знаки разные то не равны
	if (sign != num.sign) return false;
	//если разные размеры то не равны
	if (size != num.size) return false;
	//иначе проверяем каждый элемент и сравниваем их
	else {
		for (int i(0);i < size; i++) {
			isEqual = digit[i] != num.digit[i] ? isEqual && false : isEqual && true;
		}
	}
	return isEqual;
}

bool LongInt::operator>(LongInt &num)
{
	//определяем размеры чисел
	ull countMax = this->size > num.size ? this->size : num.size;
	ull countMin = this->size > num.size ? num.size : this->size;
	//если знаки разные то больше то у которого +
	if (this->sign != num.sign) return !this->sign && num.sign ? true : false;
	else {
		bool isBigger(false);
		//если размеры разные, то больше у которого размер больше
		if (size > num.size) return !sign && !num.sign ? true : false;
		else if (size < num.size) return sign && num.sign ? true : false;
		//иначе пропускаем все одинаковые цифры числа и сравниваем неодинаковые. То число у которого разряд будет больше, то и будет больше
		else if (size == num.size) {
			int i(0);
			while (digit[i] == num.digit[i] && i < countMax) i++;
			isBigger = digit[i] > num.digit[i] ? 1 - sign : 0 + sign;
		}
		return isBigger;
	}
}

bool LongInt::operator<(LongInt & num)
{
	//определяем размеры чисел
	ull countMax = this->size > num.size ? this->size : num.size;
	ull countMin = this->size > num.size ? num.size : this->size;
	//если знаки разные то меньше то у которого минус
	if (sign != num.sign) return !sign && num.sign ? false : true;
	else {
		bool isSmaller(false);
		//если размеры разные то меньше то, которого меньше размеры
		if (size > num.size) return !sign && !num.sign ? false : true;
		else if (size < num.size) return sign && num.sign ? false : true;
		//иначе пропускаем все одинаковые цифры числа и сравниваем неодинаковые.
		else if (size == num.size) {
			int i(0);
			while (digit[i] == num.digit[i] && i < countMax) i++;
			isSmaller =  digit[i] < num.digit[i] ? 1 - sign : 0 + sign;
		}
			

		return isSmaller;
	}
}

bool LongInt::operator>=(LongInt & num)
{
	//отрицание знака меньше есть больше или равно
		return !(*this < num);
}


bool LongInt::operator<=(LongInt & num)
{
	//отрицание знака больше есть меньше или равно
	return !(*this > num);
}

bool LongInt::operator!=(LongInt & num)
{
	//отрицание равенства есть неравенство
	return !(*this == num);
}

bool LongInt::operator==(long long num)
{
	LongInt a;
	a << num;
	return *this == a;
}

bool LongInt::operator>(long long num)
{
	LongInt a;
	a << num;
	return *this > a;
}

bool LongInt::operator<(long long num)
{
	LongInt a;
	a << num;
	return *this < a;
}

bool LongInt::operator>=(long long num)
{
	LongInt a;
	a << num;
	return *this >= a;
}

bool LongInt::operator<=(long long num)
{
	LongInt a;
	a << num;
	return *this <= a;
}

bool LongInt::operator!=(long long num)
{
	LongInt a;
	a << num;
	return *this != a;
}

void LongInt::operator=(LongInt &num)
{
	sign = num.sign;
	if (size != num.size) resize(num.size);
	for (int i(0); i < size; i++) {
		digit[i] = num.digit[i];
	}
}

bool LongInt::resize(ull count)
{
	//выделяем память под массив, в который будем заносить цифры числа.
	short *temp = NULL;
	temp = new short[count];
	//заносим цифры числа в доп. массив
	for (int i(size - 1); i >= (long long)(size - count); i--) {
		temp[i + count - size] = i >= 0 ? digit[i] : 0;
	}

	//удаляем старый массив чисел и снова выделяем под него память
	delete[] digit;
	size = count;
	digit = new short[size];

	//переносим цифры из доп. массива в наше число
	for (int i(0); i < size; i++) {
		digit[i] = temp[i];
	}
	delete [] temp;

	return 1;
}

void LongInt::Show(const int OnNewLine)
{
	if (sign) cout << '-';
	for (int i(0); i < size; i++) {
		cout << digit[i];
	}
	//перенос на новую строку
	if (OnNewLine) cout << endl;
}

void LongInt::operator << (const char *num)
{
	//определяем кол-во цифр в числе
	ull count = strlen(num);
	//определяем знак
	if (num[0] == '-') {
		count--;
		sign = true;
	}
	
	//подгоняем число под кол-во цифр
	if (size != count) resize(count);

	//заполняем цифрами
	for (int i((int)sign); i < count + (int)sign; i++) {
		digit[i - (int)sign] = num[i] - '0';
	}
}

void LongInt::operator<<(const long long num)
{
	//вводим числа и проверяем знак
	long long temp = abs(num);
	ull count(0);

	if (num < 0) {
		sign = true;
	}

	//считаем сколько чисел в числе
	while (temp) {
		count++;
		temp /= 10;
	}
	//подгоняем число под размеры
	if (count != size) resize(count);
	//выделяем цифры и заносим их в число
	temp = abs(num);
	for (int i(count - 1); i >= 0; i--) {
		digit[i] = temp % 10;
		temp /= 10;
	}
}

LongInt ABS(LongInt &num)
{
	LongInt* result = new LongInt;
	*result = num;
	//деляем число положительным
	result->sign = 0;
	
	return *result;
	result->~LongInt();
}

LongInt POW(LongInt & a, ull n)
{
	LongInt* result = new LongInt;
	*result << 1;
	
	for (ull i(1); i <= n; i++) {
		*result = *result * a;
	}
	return *result;
	result->~LongInt();
}

LongInt GCD(LongInt & a, LongInt & b)
{
	LongInt* First = new LongInt;
	LongInt* Second = new LongInt;
	*First = a;
	*Second = b;
	while (*First != *Second) {
		if (*First > *Second) *First = *First - *Second;
		else *Second = *Second - *First;
	}
	return *First;
	First->~LongInt();
	Second->~LongInt();
}

LongInt operator+(LongInt &a, LongInt &b)
{
	LongInt *result = new LongInt;//результат
	LongInt *First = new LongInt;//первое слогаемое
	LongInt *Second = new LongInt;//второе слогаемое

	//считаем кол-во цифр которое нужно для ответа
	ull countMax = a.size > b.size ? a.size : b.size;
	ull countMin = a.size > b.size ? b.size : a.size;

	bool doOnce(false);//false - не меняли знаки местами, иначе поменяли

	//Первое слогаемое всегда по модулю больше чем второе
	*First = ABS(a) < ABS(b) ? b : a;
	*Second = ABS(a) < ABS(b) ? a : b;

	//всегда из первого вычитаем второе, а не на оборот
	if (First->sign && !Second->sign) {
		First->sign = !First->sign;
		Second->sign = !Second->sign;
		doOnce = true;
	}

	//коеффициент знака каждого числа (ИСПОЛЬЗУЕТСЯ В ВЫЧИТАНИИ)
	short Asign = First->sign ? -1 : 1;
	short Bsign = Second->sign ? -1 : 1;
	
	//подгоняем ответ под кол-во цифр
	if (countMax == countMin && First->digit[0] * Asign + Second->digit[0] * Bsign >= 10) countMax++;
	result->resize(countMax);
	
	//цикл поразрядного суммирования
	for (int i(countMax - 1); i >= 0; i--) {		
		//прибавляем к каждому разряду разряд 1 числа, а затем второго
		if (i - (long long)countMax + (long long)First->size >= 0) 
			result->digit[i] += Asign != Bsign ? First->digit[i - (long long)countMax + (long long)First->size] * Asign 
										: First->digit[i - (long long)countMax + (long long)First->size];

		if (i - (long long)countMax + (long long)Second->size >= 0)
			result->digit[i] += Asign != Bsign ? Second->digit[i - (long long)countMax + (long long)Second->size] * Bsign
							: Second->digit[i - (long long)countMax + (long long)Second->size];

		//занимаем из следующего разряда 10
		if (result->digit[i] < 0){ 
			//result->sign = result->sign + 1;
			if (i > 0) result->digit[i - 1]--;
			result->digit[i] += 10;
		}
		//прибавляем к следующему разряду десятку
		if (result->digit[i] >= 10) {
			if (i > 0) result->digit[i - 1] += result->digit[i] / 10;
			result->digit[i] = result->digit[i] % 10;
		}
	}
	//убираем лишние нули спереди
	int i(0);
	while (result->digit[i] == 0 && i < countMax - 1) {
		countMax--;
		i++;
	}
	result->resize(countMax);

	//определяем конечный знак ответа
	result->sign = doOnce || a.sign && b.sign ? !result->sign : result->sign;

	//result->Show();
	First->~LongInt();
	Second->~LongInt();
	return *result;
	result->~LongInt();
}


LongInt operator-(LongInt & a, LongInt & b)
{
	//вычитание это тоже самое что и сложение, но у второго числа просто меняем знак
	LongInt *Second = new LongInt;
	*Second = b;
	Second->sign = !Second->sign;
	return (a + *Second);
	Second->~LongInt();
}

LongInt operator*(LongInt &a, LongInt &b)
{
	LongInt* result = new LongInt;//результат
	LongInt* First = new LongInt;//первое число
	LongInt* Second = new LongInt;//второе число

	//Первое число всегда больше второго
	*First = a > b ? a : b;
	*Second = a > b ? b : a;

	//считаем сколько примерно цифр будет в ответе
	ull count = a.size + b.size;
	result->resize(count);

	//суть эти циклов передаст пример: 123 * 123 = 123 * (123 * 1 * 00 + 123 * 2 * 10 + 123 * 3)
	//т.е. начинаем поразрядно умножать первое число на разряд второго числа и увеличивать в 10, 100 и т.д. раз в зависимости от разряда
	for (int i(Second->size - 1); i >= 0; i--) {
		LongInt temp;//результат умножения разряда числа b на все число a
		temp.resize(First->size + Second->size - i);

		for (int j(First->size); j >= 1; j--) {
			temp.digit[j] += First->digit[j - 1] * Second->digit[i];

			if (temp.digit[j] >= 10) {
				temp.digit[j - 1] += temp.digit[j] / 10;
				temp.digit[j] %= 10;
			}

		}
		*result = *result + temp;
	}

	/*int i(0);
	while (result->digit[i] == 0 && i < count - 1) {
		count--;
		i++;
	}
	result->resize(count);*/

	//определяем знак результата
	result->sign = a.sign == b.sign ? 0 : 1;

	First->~LongInt();
	Second->~LongInt();
	return *result;
	result->~LongInt();
}

LongInt operator+(LongInt & a, long long b)
{
	LongInt num;
	num << b;
	return (a + num);
}

LongInt operator-(LongInt & a, long long b)
{
	LongInt num;
	num << -b;
	return (a + num);
}

LongInt operator*(LongInt & a, long long b)
{
	LongInt num;
	num << b;
	return (a * num);
}

/*
This is my first library. This class describe long int and can work with very long numbers.
Today 30.09.2017 and today my class comlpleted.
All rights reserved by Goldnotch
*/