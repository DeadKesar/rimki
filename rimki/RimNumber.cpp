#include "RimNumber.h"



void RimNumber::Paste(std::string& rim, std::string ch, int count)
{
    for (int i = 0; i < count; i++)
    {
        rim += ch;
    }
}

int RimNumber::RimToArab(std::string rim)
{
    if (rim.length() == 1 && std::toupper(rim[0]) == 'N')
    {
        return 0;
    }
    int num = 0, countI = 0, countV = 0, countX = 0, countL = 0, countC = 0, countD = 0, countM = 0, countIV = 0,
        countIX = 0, countXL = 0, countXC = 0, countCD = 0, countCM = 0;
    for (int i = 0, length = rim.length(); i < length; i++)
    {
        switch (std::toupper(rim[i]))
        {
        case ('-'):
        {
            break;
        }
        case ('I'):
        {
            if (i + 1 < length && std::toupper(rim[i + 1]) == 'V')
            {
                num -= 2;
                countI--;
                countIV++;
            }
            if (i + 1 < length && std::toupper(rim[i + 1]) == 'X')
            {
                num -= 2;
                countI--;
                countIX++;
            }
            if (i + 1 < length && (std::toupper(rim[i + 1]) == 'L' || std::toupper(rim[i + 1]) == 'C' || std::toupper(rim[i + 1]) == 'D' || std::toupper(rim[i + 1]) == 'M'))
            {
                return -1;
            }
            num += 1;
            countI++;
            break;
        }
        case ('V'):
        {
            if (i + 1 < length && (std::toupper(rim[i + 1]) == 'X' || std::toupper(rim[i + 1]) == 'L' || std::toupper(rim[i + 1]) == 'C' || std::toupper(rim[i + 1]) == 'D' || std::toupper(rim[i + 1]) == 'M'))
            {
                return -1;
            }
            num += 5;
            countV++;
            break;
        }
        case (L'X'):
        {
            if (i + 1 < length && std::toupper(rim[i + 1]) == 'L')
            {
                num -= 20;
                countX--;
                countXL++;
            }
            if (i + 1 < length && std::toupper(rim[i + 1]) == 'C')
            {
                num -= 20;
                countX--;
                countXC++;
            }
            if (i + 1 < length && (std::toupper(rim[i + 1]) == 'D' || std::toupper(rim[i + 1]) == 'M'))
            {
                return -1;
            }
            num += 10;
            countX++;
            break;
        }
        case (L'L'):
        {
            if (i + 1 < length && (std::toupper(rim[i + 1]) == 'C' || std::toupper(rim[i + 1]) == 'D' || std::toupper(rim[i + 1]) == 'M'))
            {
                return -1;
            }
            num += 50;
            countL++;
            break;
        }
        case ('C'):
        {
            if (i + 1 < length && std::toupper(rim[i + 1]) == 'D')
            {
                num -= 200;
                countC--;
                countCD++;
            }
            if (i + 1 < length && std::toupper(rim[i + 1]) == 'M')
            {
                num -= 200;
                countC--;
                countCM++;
            }
            num += 100;
            countC++;
            break;
        }
        case ('D'):
        {
            num += 500;
            countD++;
            break;
        }
        case ('M'):
        {
            num += 1000;
            countM++;
            break;
        }
        default:
            return -1;
            break;
        }
    }
    //проверка правил построения римского числа: меньшие числа не стоят перед большими кроме особого случая когда число предыдущего разряда
    // вычитается, нет ситуаций когда из числа сначала вычли единицу, а потом добавили.
    //
    if (countI > 3 || countV > 1 || countX > 3 || countL > 1 || countC > 3 || countD > 1 || countM > 10 ||
        countIV > 1 || countIX > 1 || countXL > 1 || countXC > 1 || countCD > 1 || countCM > 1 ||
        (countIV == 1 && countIX == 1) || (countIV == 0 && countIX == 1 && countV > 0) ||
        (countXL == 1 && countXC == 1) || (countXL == 0 && countXC == 1 && countL > 0) ||
        (countCD == 1 && countCM == 1) || (countCD == 0 && countCM == 1 && countD > 0) ||
        (countIX == 1 && countI > 0) || (countIV == 1 && countI > 0) ||
        (countXC == 1 && countX > 0) || (countXL == 1 && countXC > 0) ||
        (countCM == 1 && countC > 0) || (countCD == 1 && countC > 0))
    {
        return -1;
    }
    return num;
}
void RimNumber::SetByArab(int numb)
{
    arabNumb = numb;
    std::string answer = "";
    bool isMinus = false;
    if (numb == 0)
    {
        answer = "N";
    }
    if (numb < 0)
    {
        isMinus = true;
        Paste(answer, "-");
        numb *= (-1);
    }
    if (numb / 1000 > 0)
    {
        Paste(answer, "M", numb / 1000);
        numb %= 1000;
    }
    if (numb / 900 > 0)
    {
        Paste(answer, "CM", numb / 900);
        numb %= 900;
    }
    if (numb / 500 > 0)
    {
        Paste(answer, "D", numb / 500);
        numb %= 500;
    }
    if (numb / 400 > 0)
    {
        Paste(answer, "CD", numb / 400);
        numb %= 400;
    }
    if (numb / 100 > 0)
    {
        Paste(answer, "C", numb / 100);
        numb %= 100;
    }
    if (numb / 90 > 0)
    {
        Paste(answer, "XC", numb / 90);
        numb %= 90;
    }
    if (numb / 50 > 0)
    {
        Paste(answer, "L", numb / 50);
        numb %= 50;
    }
    if (numb / 40 > 0)
    {
        Paste(answer, "XL", numb / 40);
        numb %= 40;
    }
    if (numb / 10 > 0)
    {
        Paste(answer, "X", numb / 10);
        numb %= 10;
    }
    if (numb / 9 > 0)
    {
        Paste(answer, "IX", numb / 9);
        numb %= 9;
    }
    if (numb / 5 > 0)
    {
        Paste(answer, "V", numb / 5);
        numb %= 5;
    }
    else if (numb / 4 > 0)
    {
        Paste(answer, "IV", numb / 4);
        numb %= 4;
    }
    if (numb >= 1)
    {
        Paste(answer, "I", numb / 1);
        numb--;
    }
    rim = answer;
}
void RimNumber::CallSetFromConsole(std::string const mes)
{
    std::cout << (mes);
    bool isSuccess = true;
    while (isSuccess)
    {
        std::cin >> *this;
        isSuccess = false;
        if ((int)*this == -1)
        {
            std::wcout << std::endl << L"Римское число не коректно. Попробуйте снова: ";
            isSuccess = true;
        }
    }
    if (rim[0] == '-' && arabNumb == 1)
    {
        arabNumb *= -1;
    }
}
std::string RimNumber::GetRim()
{
    return this->rim;
}
double RimNumber::GetArab()
{
    return this->arabNumb;
}
RimNumber RimNumber::operator+(RimNumber aRim)
{
    RimNumber temp;
    temp.SetByArab(this->arabNumb + aRim.arabNumb);
    return temp;
}
RimNumber RimNumber::operator-(RimNumber aRim)
{
    RimNumber temp;
    temp.SetByArab(this->arabNumb - aRim.arabNumb);
    return temp;
}
RimNumber RimNumber::operator*(RimNumber aRim)
{
    RimNumber temp;
    temp.SetByArab(this->arabNumb * aRim.arabNumb);
    return temp;
}
RimNumber RimNumber::operator/(RimNumber aRim)
{
    RimNumber temp;
    if (aRim.arabNumb == 0)
    {
        std::wcout << L"Делить на 0 нельзя." << std::endl;
        temp.SetByArab(0);
        return temp;
    }
    temp.SetByArab(this->arabNumb / aRim.arabNumb);
    return temp;
}



RimNumber RimNumber::operator+(int num)
{
    RimNumber temp;
    temp.SetByArab(this->arabNumb + num);
    return temp;
}
RimNumber RimNumber::operator-(int num)
{
    RimNumber temp;
    temp.SetByArab(this->arabNumb - num);
    return temp;
}
RimNumber RimNumber::operator*(int num)
{
    RimNumber temp;
    temp.SetByArab(this->arabNumb * num);
    return temp;
}
RimNumber RimNumber::operator/(int num)
{
    RimNumber temp;
    if (num == 0)
    {
        std::wcout << L"Делить на 0 нельзя." << std::endl;
        temp.SetByArab(0);
        return temp;
    }
    temp.SetByArab(this->arabNumb / num);
    return temp;
}
RimNumber& RimNumber::operator=(int num)
{
    this->SetByArab(num);
    return *this;
}
RimNumber& RimNumber::operator=(RimNumber& rim)
{
    if (*this == rim)
    {
        return *this;
    }
    this->arabNumb = rim.arabNumb;
    this->rim = rim.rim;
    return *this;
}

RimNumber& RimNumber::operator+=(RimNumber& aRim)
{
    this->SetByArab(this->arabNumb + aRim.arabNumb);
    return *this;
}
RimNumber& RimNumber::operator-=(RimNumber& aRim)
{
    this->SetByArab(this->arabNumb - aRim.arabNumb);
    return *this;
}
RimNumber& RimNumber::operator*=(RimNumber& aRim)
{
    this->SetByArab(this->arabNumb * aRim.arabNumb);
    return *this;
}
RimNumber& RimNumber::operator/=(RimNumber& aRim)
{
    if (aRim.arabNumb == 0)
    {
        std::wcout << L"Делить на 0 нельзя." << std::endl;
        this->SetByArab(0);
        return *this;
    }
    this->SetByArab(this->arabNumb / aRim.arabNumb);
    return *this;
}
RimNumber& RimNumber::operator+=(int num)
{
    this->SetByArab(this->arabNumb + num);
    return *this;
}
RimNumber& RimNumber::operator-=(int num)
{
    this->SetByArab(this->arabNumb - num);
    return *this;
}
RimNumber& RimNumber::operator*=(int num)
{
    this->SetByArab(this->arabNumb * num);
    return *this;
}
RimNumber& RimNumber::operator/=(int num)
{
    if (num == 0)
    {
        std::wcout << L"Делить на 0 нельзя." << std::endl;
        this->SetByArab(0);
        return *this;
    }
    this->SetByArab(this->arabNumb / num);
    return *this;
}
RimNumber& RimNumber::operator++()
{
    this->arabNumb++;
    this->SetByArab(this->arabNumb);
    return *this;
}
RimNumber RimNumber::operator++(int)
{
    RimNumber temp = *this;
    this->arabNumb++;
    this->SetByArab(this->arabNumb);
    return temp;
}
RimNumber& RimNumber::operator--()
{
    this->arabNumb--;
    this->SetByArab(this->arabNumb);
    return *this;
}
RimNumber RimNumber::operator--(int)
{
    RimNumber temp = *this;
    this->arabNumb--;
    this->SetByArab(this->arabNumb);
    return temp;
}

bool  RimNumber::operator>(RimNumber rim)
{
    return this->arabNumb > rim.arabNumb;
}
bool  RimNumber::operator>(int num)
{
    return this->arabNumb > num;
}
bool  RimNumber::operator<(RimNumber rim)
{
    return this->arabNumb < rim.arabNumb;
}
bool  RimNumber::operator<(int num)
{
    return this->arabNumb < num;
}
bool  RimNumber::operator>=(RimNumber rim)
{
    return this->arabNumb >= rim.arabNumb;
}
bool  RimNumber::operator>=(int num)
{
    return this->arabNumb >= num;
}
bool  RimNumber::operator<=(RimNumber rim)
{
    return this->arabNumb <= rim.arabNumb;
}
bool  RimNumber::operator<=(int num)
{
    return this->arabNumb <= num;
}
bool  RimNumber::operator==(RimNumber rim)
{
    return this->arabNumb == rim.arabNumb;
}
bool  RimNumber::operator==(int num)
{
    return this->arabNumb == num;
}
bool  RimNumber::operator!=(RimNumber rim)
{
    return this->arabNumb != rim.arabNumb;
}
bool  RimNumber::operator!=(int num)
{
    return this->arabNumb != num;
}


RimNumber::operator int()
{
    return this->arabNumb;
}
std::ostream& operator<<(std::ostream& os, RimNumber& rim)
{
    os << rim.rim;
    return os;
}
std::istream& operator>>(std::istream& is, RimNumber& rim)
{
    std::string temp;
    double num = 0;
    is >> temp;

    rim.TryToGetNumber(temp);
    if (rim.arabNumb != -1)
    {
        if (temp[0] == L'-' && (rim.arabNumb != -1 && rim.arabNumb != 1))
        {
            rim.arabNumb *= -1;
        }
        rim.SetByArab(rim.arabNumb);
        return is;
    }
    {
        rim.arabNumb = rim.RimToArab(temp);
        if (temp[0] == L'-' && (rim.arabNumb != -1 && rim.arabNumb != 1))
        {
            rim.arabNumb *= -1;
        }
        rim.SetByArab(rim.arabNumb);
    }
    return is;

}

RimNumber& RimNumber::TryToGetNumber(std::string s)
{
    this->arabNumb = 0;
    int n = s.length() - 1;
    for (int i = n; i >= 0; i--)
    {
        if ((int)s[i] >= L'0' && (int)s[i] <= L'9')
        {
            this->arabNumb += (s[i] - L'0') * pow(10, n - i);
        }
        else if (s[i] == L'-')
        {
            continue;
        }
        else
        {
            this->arabNumb = -1;
            return *this;
        }
    }
    return *this;
}