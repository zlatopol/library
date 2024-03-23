#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cstdio>

using namespace std;

const int quantity = 100;// Размер выделяемой памяти

//*********************************************

//input_int(message, min, max)
int input_int(string message, int min, int max)
{
    int n = min;

    cout << message << endl;
    cin >> n;

    while ((cin.fail()) || (n < min) || (n > max))
    {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(BUFSIZ, '\n');
        //cin.sync();
        cout << "Поддерживаются целые числовые значения от " << min << " до " << max << endl << message << endl;
        cin >> n;
    }
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(BUFSIZ, '\n');
    //cin.sync();
    return n;
}

string input_string(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str, '\n');
    return str;
}

//*********************************

std::string check_file_in_open(string message)
{
    std::string filename = "";
    do {
        filename = input_string(message); // "Введите название файла: "
        std::ifstream file;
        file.open(filename);
        if (file.is_open()) {
            file.close();
            return filename;
        }
        std::cout << "Не удалось открыть файл!\n";
    } while (true);
}

std::string check_file_out_open(string message)
{
    std::string filename = "";
    do {
        filename = input_string(message); // "Введите название файла: "
        std::ofstream file;
        file.open(filename);
        if (file.is_open()) {
            file.close();
            return filename;
        }
        std::cout << "Не удалось открыть файл!\n";
    } while (true);
}

int fileSize(std::string filename)
{
    std::fstream file;
    file.open(filename);

    int lineCount = 0;
    std::string trash;

    while (!file.eof())
    {
        getline(file, trash);
        lineCount++;
    }

    if (trash == "")
    {
        lineCount--;
    }

    file.close();
    return lineCount;
}
