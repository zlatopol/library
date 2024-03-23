#pragma once

#include "Header.h"

struct Doctor
    //создания структуры книги с переменными номер surname, название книги, автор, количество штук и год издания.
{
    public:
        std::string surname;
        std::string name;
        std::string patronymic;
        std::string speciality;
        std::string skill_level;

    Doctor(//инициализация структуры
        std::string surname = "",
        std::string name = "",
        std::string patronymic = "",
        std::string speciality = "",
        std::string skill_level = ""
    ) : surname(surname),
        name(name),
        patronymic(patronymic),
        speciality(speciality),
        skill_level(skill_level)
    {}
};

/*ФУНКЦИЯ ЗАНОСИТ ДАННЫЕ В СТРУКТУРУ*/
void GetData(Doctor &doctor)
{
    doctor.surname = input_string("Введите фамилию:");
    doctor.name = input_string("Введите  имя:");
    doctor.patronymic= input_string("Введите отчество:");
    doctor.speciality = input_string("Введите специальность:");
    doctor.skill_level = input_string("Введите уровень квалификации:");
}

// Вывод сотрудника на экран
void ShowDoctor(const Doctor &doctor, int surname, int name, int patronymic, int speciality, int skill_level)
{
    std::cout << doctor.surname << std::setw(surname - doctor.surname.size() + 1) << "|";
    std::cout << doctor.name << std::setw(name - doctor.name.size() + 1) << "|";
    std::cout << doctor.patronymic << std::setw(patronymic - doctor.patronymic.size() + 1) << "|";
    std::cout << doctor.speciality << std::setw(speciality - doctor.speciality.size() + 1) << "|";
    std::cout << doctor.skill_level << std::setw(skill_level - doctor.skill_level.size() + 1) << "|";
    std::cout << '\n';
}

void ShowDoctor(const Doctor &doctor)
{
    std::cout << "Фамилия: " << doctor.surname << '\n';
    std::cout << "Имя: " << doctor.name << '\n';
    std::cout << "Отчество: " << doctor.patronymic << '\n';
    std::cout << "Специальность: " << doctor.speciality << '\n';
    std::cout << "Уровень квалификации: " << doctor.skill_level << '\n';
    std::cout << '\n';
}
// Редактирование сотрудника

void EditDoctor(Doctor &doctor)
{
    std::cout << "Фамилия: " << doctor.surname << '\n';
    doctor.surname = input_string("Введите фамилию:");
    std::cout << "Имя: " << doctor.name << '\n';
    doctor.name = input_string("Введите имя:");
    std::cout << "Отчество: " << doctor.patronymic << '\n';
    doctor.patronymic = input_string("Введите отчество:");
    std::cout << "Специальность: " << doctor.speciality << '\n';
    doctor.speciality = input_string("Введите специальность:");
    std::cout << "Квалификация: " << doctor.skill_level << '\n';
    doctor.skill_level = input_string("Введите уровень квалификации:");
}

//********************************************************

void write_doctor(std::ofstream &file,const Doctor &doctor) 
{
    file << doctor.surname << ";" << doctor.name << ";" << doctor.patronymic << ";"
        << doctor.speciality << ";" << doctor.skill_level << ";\n";
}

void read_doctor(std::ifstream &file, Doctor &doctor) 
{
    std::string buffer = "";
    getline(file, buffer, '\n');
    int start = 0;
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        k = buffer.find(';', start);
        if (k != std::string::npos)
        {
            switch (i)
            {
            case 0:
                doctor.surname = buffer.substr(start, k - start);
                break;
            case 1:
                doctor.name = buffer.substr(start, k - start);
                break;
            case 2:
                doctor.patronymic = buffer.substr(start, k - start);
                break;
            case 3:
                doctor.speciality = buffer.substr(start, k - start);
                break;
            case 4:
                doctor.skill_level = buffer.substr(start, k - start);
                break;
            }
            start = k + 1;
        }
        else
        {
            break;
        }
    }
}
