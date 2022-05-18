#pragma once
#pragma once
#include <string>
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <math.h>

class RimNumber
{

private:
	std::string rim = "N";
	int arabNumb = 0;
	int RimToArab(std::string rim);
	static std::string FractionToRim(double num);
	static void  Paste(std::string& rim, std::string ch, int count = 1);
	RimNumber& TryToGetNumber(std::string s);
public:
	void SetByArab(int num);
	void CallSetFromConsole(std::string const mes);
	std::string GetRim();
	double GetArab();
	RimNumber operator+(RimNumber aRim);
	RimNumber operator-(RimNumber aRim);
	RimNumber operator*(RimNumber aRim);
	RimNumber operator/(RimNumber aRim);
	RimNumber operator+(int num);
	RimNumber operator-(int num);
	RimNumber operator*(int num);
	RimNumber operator/(int num);
	operator int();
	RimNumber& operator=(int num);
	RimNumber& operator=(RimNumber& rim);
	RimNumber& operator+=(RimNumber& aRim);
	RimNumber& operator-=(RimNumber& aRim);
	RimNumber& operator*=(RimNumber& aRim);
	RimNumber& operator/=(RimNumber& aRim);
	RimNumber& operator+=(int num);
	RimNumber& operator-=(int num);
	RimNumber& operator*=(int num);
	RimNumber& operator/=(int num);
	RimNumber& operator++();
	RimNumber operator++(int);
	RimNumber& operator--();
	RimNumber operator--(int);
	bool operator>(RimNumber rim);
	bool operator>(int num);
	bool operator<(RimNumber rim);
	bool operator<(int num);
	bool operator>=(RimNumber rim);
	bool operator>=(int num);
	bool operator<=(RimNumber rim);
	bool operator<=(int num);
	bool operator==(RimNumber rim);
	bool operator==(int num);
	bool operator!=(RimNumber rim);
	bool operator!=(int num);
	friend std::ostream& operator<<(std::ostream& os, RimNumber& rim);
	friend std::istream& operator>>(std::istream& is, RimNumber& rim);
};

