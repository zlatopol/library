#pragma once

#include "Header.h"

struct Doctor
    //�������� ��������� ����� � ����������� ����� surname, �������� �����, �����, ���������� ���� � ��� �������.
{
    public:
        std::string surname;
        std::string name;
        std::string patronymic;
        std::string speciality;
        std::string skill_level;

    Doctor(//������������� ���������
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

/*������� ������� ������ � ���������*/
void GetData(Doctor &doctor)
{
    doctor.surname = input_string("������� �������:");
    doctor.name = input_string("�������  ���:");
    doctor.patronymic= input_string("������� ��������:");
    doctor.speciality = input_string("������� �������������:");
    doctor.skill_level = input_string("������� ������� ������������:");
}

// ����� ���������� �� �����
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
    std::cout << "�������: " << doctor.surname << '\n';
    std::cout << "���: " << doctor.name << '\n';
    std::cout << "��������: " << doctor.patronymic << '\n';
    std::cout << "�������������: " << doctor.speciality << '\n';
    std::cout << "������� ������������: " << doctor.skill_level << '\n';
    std::cout << '\n';
}
// �������������� ����������

void EditDoctor(Doctor &doctor)
{
    std::cout << "�������: " << doctor.surname << '\n';
    doctor.surname = input_string("������� �������:");
    std::cout << "���: " << doctor.name << '\n';
    doctor.name = input_string("������� ���:");
    std::cout << "��������: " << doctor.patronymic << '\n';
    doctor.patronymic = input_string("������� ��������:");
    std::cout << "�������������: " << doctor.speciality << '\n';
    doctor.speciality = input_string("������� �������������:");
    std::cout << "������������: " << doctor.skill_level << '\n';
    doctor.skill_level = input_string("������� ������� ������������:");
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
