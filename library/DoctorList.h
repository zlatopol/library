#pragma once

#include "Doctor.h"

void clean(Doctor* doctor,  int& n)
{
    delete[] doctor;
    doctor = new Doctor[quantity];
    n = 0;
    std::cout << "������ ������.\n";
}

//***********************************

/*��������������� �������, ���� ������������ ������ ��� ������ �������*/
/*���������� ���� � �����*/
int number_of_digits(int n) {
    if (n == 0) return 1;
    int i = 0;
    while (n > 0) {
        n /= 10;
        i++;
    }
    return i;
}
int get_max_surname(Doctor* doctor, const int& n) {
    int maximum = doctor->surname.size() + 1;
    int temp;
    for (int i = 1; i < n; i++) {
        temp = doctor[i].surname.size() + 1;
        if (temp > maximum) maximum = temp;
    }
    return maximum;
}

int get_max_name(Doctor* doctor, const int& n) {
    int maximum = doctor->name.size() + 1;
    int temp;
    for (int i = 1; i < n; i++) {
        temp = doctor[i].name.size() + 1;
        if (temp > maximum) maximum = temp;
    }
    return maximum;
}

int get_max_patronymic(Doctor* doctor, const int& n) {
    int maximum = doctor->patronymic.size() + 1;
    int temp;
    for (int i = 1; i < n; i++) {
        temp = doctor[i].patronymic.size() + 1;
        if (temp > maximum) maximum = temp;
    }
    return maximum;
}

int get_max_speciality(Doctor* doctor, const int& n) {
    int maximum = doctor->speciality.size() + 1;
    int temp;
    for (int i = 1; i < n; i++) {
        temp = doctor[i].speciality.size() + 1;
        if (temp > maximum) maximum = temp;
    }
    return maximum;
}

int get_max_skill_level(Doctor* doctor, const int& n) {
    int maximum = doctor->skill_level.size() + 1;
    int temp;
    for (int i = 1; i < n; i++) {
        temp = doctor[i].skill_level.size() + 1;
        if (temp > maximum) maximum = temp;
    }
    return maximum;
}

/*������� ������������ ����� ������ �� �����*/
void ShowData(Doctor* doctor, const int &n)
{
    std::cout << "\n\n";
    std::cout << "������ ��������: \n";
    struct ColumnWidth {     //��������������� ��������� ������� ������������ ������������� ������
        int surname = strlen("�������") + 1;
        int name = strlen("���") + 1;
        int patronymic = strlen("��������") + 1;
        int speciality = strlen("�������������") + 1;
        int skill_level = strlen("������� ������������") + 1;
    } ColumnWidth;
    int temp = 0;               //���������� ��� �������� ���������� ������

    /*����ר� ������ ������ ��������*/
    temp = get_max_surname(doctor, n);
    if (ColumnWidth.surname < temp) ColumnWidth.surname = temp;
    temp = get_max_name(doctor, n);
    if (ColumnWidth.name < temp) ColumnWidth.name = temp;
    temp = get_max_patronymic(doctor, n);
    if (ColumnWidth.patronymic < temp) ColumnWidth.patronymic = temp;
    temp = get_max_speciality(doctor, n);
    if (ColumnWidth.speciality < temp) ColumnWidth.speciality = temp;
    temp = get_max_skill_level(doctor, n);
    if (ColumnWidth.skill_level < temp) ColumnWidth.skill_level = temp;
    /*����� ���ר��*/
    /*������-���������*/
    std::cout << "�����" << std::setw(1) << "|";
    std::cout << "�������" << std::setw(ColumnWidth.surname - strlen("�������") + 1) << "|";
    std::cout << "���" << std::setw(ColumnWidth.name - strlen("���") + 1) << "|";
    std::cout << "��������" << std::setw(ColumnWidth.patronymic - strlen("��������") + 1) << "|";
    std::cout << "�������������" << std::setw(ColumnWidth.speciality - strlen("�������������") + 1) << "|";
    std::cout << "������� ������������" << std::setw(ColumnWidth.skill_level - strlen("������� ������������") + 1) << "|";
    /*����� �����-����������*/
    std::cout << '\n';
    for (int i = 0; i < n; i++)
    {
        std::cout << i+1 << std::setw(strlen("�����") - number_of_digits(i) + 1) << "|";
        ShowDoctor(*doctor, ColumnWidth.surname, ColumnWidth.name, ColumnWidth.patronymic, ColumnWidth.speciality, ColumnWidth.skill_level);
        doctor++;
    }
}

void write_list(Doctor* doctor, const int &n)
{
    if (n == 0)
    {
        std::cout << "� ��������� ������ ���� ����.";
    }
    else {
        ShowData(doctor, n);
    }
}

// ������� �� ����������� ������
void ShowNumber(Doctor* doctor, const int &n)
{
    int  i = input_int("������� ����� ����������, �������� ������ �������: \n", 1, n);
    ShowDoctor(doctor[i-1]);

}
//********************************************

// ��������������
void EditorList(Doctor* doctor, const int &n)
{
    std::string messege = "������� ����� ����������, �������� ������ ��������.\n";
    int  i = input_int(messege, 1, n);
    EditDoctor(doctor[i-1]);
}

//**************************************

/*void search_surname(std::string Surname_, Doctor* doctor, const int& n, int* i)
{
    bool f = true;
    for (; *i < n; (*i)++)
    {
        int k = doctor[*i].surname.find(Surname_);
        if (k != std::string::npos) {
            f = false;
            break;
        }
    }
    if (f) *i = n + 1;
}
*/
void search_surname(Doctor* doctor, const int &n)
{
    std::string surname = input_string("������� ������� ����������, �������� �����: ");
    std::cout << std::endl;
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        int k = doctor[i].surname.find(surname);
        if (k != std::string::npos) {
            f = true;
            std::cout << "����� ����������: " << i + 1 << '\n';
            ShowDoctor(doctor[i]);
            std::cout << std::endl;
        }
    }
    if (f == false)
        std::cout << "���������� � ����� �������� �� �������.\n";
}
//�������� ��� ������� ������ (��� ���� ��������� ��� � ����� ���������� �������)

/*void search_skill_level(std::string Skill_level_, Doctor* doctor, const int& n, int* i)
{
    bool f = true;
    for (; *i < n; (*i)++)
    {
        int k = doctor[*i].skill_level.find(Skill_level_);
        if (k != std::string::npos) {
            f = false;
            break;
        }
    }
    if (f) *i = n + 1;
}*/
void search_skill_level(Doctor* doctor, const int& n)
{
    std::string skill_level = input_string("������� ������� ������������ ����������, �������� �����: ");
    std::cout << std::endl;
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        int k = doctor[i].skill_level.find(skill_level);
        if (k != std::string::npos) {
            f = true;
            std::cout << "����� ����������: " << i + 1 << '\n';
            ShowDoctor(doctor[i]);
            std::cout << std::endl;
        }
    }
    if (!f)
        std::cout << "���������� � ����� �������� �� �������.\n";

}

//�������� ��� ������� ������ (��� ���� ��������� ��� � ����� ���������� �������)

void swap_(Doctor* a, Doctor* b)
{
    swap((*a).surname, (*b).surname);
    swap((*a).name, (*b).name);
    swap((*a).patronymic, (*b).patronymic);
    swap((*a).speciality, (*b).speciality);
    swap((*a).skill_level, (*b).skill_level);
}

void ad_doctor(Doctor* doctor, int &n)
{
    if (n >= quantity)
    {
        std::cout << "���������� ������� ����� �������!\n";
    }
    else
    {
        if (n != 0)
        {
            int num = input_int("� ����� ����� ������ �������� ����� ������: ", 1, ++n) - 1;
            for (int i = n; i > num; i--)
            {
                swap_(doctor + i, doctor + i - 1);
            }
            GetData(doctor[num]);
        }
        else
        {
            GetData(doctor[n++]);
        }
    }
}


//*****************************************

void sort_surname(Doctor* doctor, const int &n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (doctor[j].surname > doctor[i].surname) swap_(doctor + j, doctor + i);
}

void sort_skill_level(Doctor* doctor, const int &n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (doctor[j].skill_level > doctor[i].skill_level) swap_(doctor + j, doctor + i);
}

//****************************************

// �������� ���������� �� ������
void delete_doctor(Doctor* doctor, int &n) {
    int num = input_int("������� ����� ����������, �������� ������ �������.", 1, n) - 1;
    //Doctor NUL("", "", "", "", "");
    //doctor[num] = NUL;
    n--;
    for (int i = num; i < n; i++)
    {
        swap_(doctor + i, doctor + i + 1);
    }
}

//********************************


void fileRead(Doctor* inputdoc, int& n)
{
    std::string filename = check_file_in_open("������� �������� �����: ");
    std::ifstream file;
    file.open(filename);

    n = fileSize(filename);


    for (int i = 0; i < n; i++)
    {
        read_doctor(file, inputdoc[i]);
    }
    file.close();
}

void fileWrite(Doctor* inputdoc, int& n)
{
    std::string filename = check_file_out_open("������� �������� �����: ");
    std::ofstream file;
    file.open(filename);

    for (int i = 0; i < n; i++)
    {
        write_doctor(file, *inputdoc);
        inputdoc++;
    }
}

//*******************************************


