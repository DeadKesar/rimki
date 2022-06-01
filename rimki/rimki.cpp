
#include "RimNumber.h"
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::string path1("out1.bin");
    RimNumber rim1,rim2,rim3;
    rim1.SetByArab(2);
    rim2.SetByArab(233);
    rim3.SetByArab(23444);
    
    std::cout << sizeof(std::string) << "\n";
    std::cout << sizeof(rim1) << "\n";
    std::cout << sizeof(rim2) << "\n";
    std::cout << sizeof(rim3) << "\n";
    std::cout << sizeof(RimNumber) << "\n";
    
    RimNumber *rims = new RimNumber[]{rim1,rim2,rim3};
   /* std::ofstream write;
    write.open(path1, std::ifstream::binary);
    if (!write)
    {
        std::cout << "not open! \n";
    }
    else
    {
        std::cout << "file open! \n";
        write.write((char*)rims, sizeof(RimNumber)*3);
    }
    write.close();
    */
   /*
    std::ifstream read;
    read.open(path1, std::ifstream::binary);
    if (!read.is_open())
    {
        std::cout << "not open! \n";
    }
    else
    {
        std::cout << "file open! \n";
        RimNumber* rims = new RimNumber;
        std::vector<RimNumber> rimss;
        int i = 0,j=0;
        while (read.read((char*)rims, sizeof(RimNumber)))
        {
            i = sizeof(RimNumber);
            j = sizeof(*rims);
            rimss.push_back(*rims);

        }
        std::cout << rimss[0].GetRim() << std::endl;
        std::cout << rimss[1].GetRim() << std::endl;
        std::cout << rimss[2].GetRim() << std::endl;
    }
    read.close();
    
    */
    std::fstream fs;
    /*fs.open(path1, std::fstream::out);
    if (!fs.is_open())
    {
        std::cout << "not open! \n";
    }
    else
    {
    std::cout << "file open! \n";
    fs.write((char*)rims, sizeof(RimNumber) * 3);
    }
    fs.close();
    delete[] rims;
    */
    
    fs.open(path1, std::fstream::in);
    if (!fs.is_open())
    {
        std::cout << "not open! \n";
    }
    else
    {
        std::cout << "file open! \n";
        RimNumber* rims = new RimNumber;
        std::vector<RimNumber> rimss;
        int i = 0, j = 0;
        while (fs.read((char*)rims, sizeof(RimNumber)))
        {
            i = sizeof(RimNumber);
            j = sizeof(*rims);
            rimss.push_back(*rims);

        }
        std::cout << rimss[0].GetRim() << std::endl;
        std::cout << rimss[1].GetRim() << std::endl;
        std::cout << rimss[2].GetRim() << std::endl;
    }
    fs.close();



}


