/*
This is my first library. This class describe long int and can work with very long numbers.
Today 30.09.2017 and today my class comlpleted.
All rights reserved by Goldnotch
*/

#pragma once
#include <iostream>
using namespace std;

#define ull unsigned long long
#define ON_NEW_LINE (int)1//������� �� ����� ������

class LongInt
{
public:
	LongInt(); //�����������
	~LongInt(); //����������

	//�������������� �������
	friend LongInt ABS(LongInt &num);//������ �����
	friend LongInt POW(LongInt &a, ull n);//���������� � �������
	friend LongInt GCD(LongInt &a, LongInt &b);

	//���������� ��������� � LongInt
	bool operator==(LongInt &num);//���������� �����
	bool operator>(LongInt& num);//������ ������
	bool operator<(LongInt& num);//������ ������
	bool operator>=(LongInt& num);//������ ��� �����
	bool operator<=(LongInt& num);//������ ��� �����
	bool operator!=(LongInt &num);//�� �����

	//���������� ��������� � long long � ������
	bool operator==(long long num);//���������� �����
	bool operator>(long long num);//������ ������
	bool operator<(long long num);//������ ������
	bool operator>=(long long num);//������ ��� �����
	bool operator<=(long long num);//������ ��� �����
	bool operator!=(long long num);//�� �����

	//�������������� ���������
	void operator= (LongInt &num);//������������
	friend LongInt operator+(LongInt &a, LongInt &b);//�������� ���� �����
	friend LongInt operator-(LongInt &a, LongInt &b);//��������� ���� �����
	friend LongInt operator*(LongInt &a, LongInt &b);//��������� ���� �����
	//�������������� �������� � ������� ���� long long(int, short � �.�.)
	friend LongInt operator+(LongInt &a, long long b);//�������� � ������
	friend LongInt operator-(LongInt &a, long long b);//��������� � ������
	friend LongInt operator*(LongInt &a, long long b);//��������� � ������
	//�� ���� ������ ������������� �������


	//input/output
	void Show(const int OnNewLine = 0);//DEBUG �������. �������� �� ��������� ����/�����
	void operator << (const char* num);//���� �� ������ (���������� ��� ����� ������� �����)
	void operator << (const long long num); // ���� �� �����
	

private:
	short *digit;//�����
	ull size;//������
	bool sign;	//���� true - �����, false = +
	bool resize(ull count);//������� ��������� ������� �����. ������� ����� ����� �� �����. 364367.resize(2) = 67

};


/*
This is my first library. This class describe long int and can work with very long numbers.
Today 30.09.2017 and today my class comlpleted.
All rights reserved by Goldnotch
*/