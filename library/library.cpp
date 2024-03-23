#include "DoctorList.h"

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Doctor* doctor_list = new Doctor[quantity];
    int amount = 0; // �������� ����������� ��������
    int punkt = 1; // ����� ����
    do
    {
        std::system("cls");
        std::cout << "�������� ����������� ��������:\n" <<
            "1. ������� ������\n" <<
            "2. �������� �������� �������\n" <<
            "3. ������� ����������� �������\n" << 
            "4. ������� ���������� �� ����������� ������\n" <<
            "5. ��������������� ������ ����������\n" <<
            "6. ����� ���������� �� �������\n" <<
            "7. ����� �� ������ ������������\n" <<
            "8. ������������� ������ �� �������\n" <<
            "9. ������������� ������ �� ������������\n"<<
            "10.�������� ���������� �� ������\n" <<
            "11.���� ������ �� �����\n" <<
            "12.����� ������ � ����\n" <<
            "0. ��������� ������\n";
        punkt = input_int("������� ����� ������ ����: \n", 0, 12);
        switch (punkt) {
        case 0:
            break;

        case 1:
            clean(doctor_list, amount);
            std::system("pause");
            break;
        case 2:
        {
            ad_doctor(doctor_list, amount);
            std::system("pause");
            break;
        }
        case 3:
        {
            write_list(doctor_list, amount);
            std::system("pause");
            break;
        }
        case 4:
        {
            int num = input_int("������� ����� ����������, �������� ������ �������\n", 1, amount) - 1;
            std::cout << "����� ����������: " << num + 1 << '\n';
            ShowDoctor(doctor_list[num]);
            std::system("pause");
            break;
        }
        case 5:
        {
            EditorList(doctor_list, amount);
            std::system("pause");
            break;
        }
        case 6:
        {
            /*std::string surname_;
            std::cout << "������� �������\n";
            std::cin >> surname_; //getline()
            int count = 0, i = 0;
            Doctor* Seach = new Doctor[quantity];
            // ������� �� ����� ������ ������� �� ���������, �� �������� � ����� ������
            while (count <= amount)
            {
                search_surname(surname_, doctor_list, amount, &count);
                if (count <= amount) Seach[i++] = doctor_list[count++];
            }
            if (i == 0) std::cout << "������ ������� �� �������\n";
            else ShowData(Seach, i);
            std::cout << '\n' << i << '\n';
            delete[]Seach;*/
            search_surname(doctor_list, amount);
            std::system("pause");
            break;
        }
        case 7:
        {
            /*std::string skill_level_;
            std::cout << "������� ������� ������������\n";
            std::cin >> skill_level_;
            int count = 0, i = 0;
            Doctor* Seach = new Doctor[quantity];
            while (count <= amount)
            {
                search_skill_level(skill_level_, doctor_list, amount, &count);
                if (count <= amount) Seach[i++] = doctor_list[count++];
            }
            if (i == 0) std::cout << "�� ������� ���������� � ����� �������������\n";
            else ShowData(Seach, i);
            std::cout << '\n' << i << '\n';
            delete[]Seach;*/
            search_skill_level(doctor_list, amount);
            std::system("pause");
            break;
        }
        case 8:
        {
            sort_surname(doctor_list, amount);
            std::cout << "������� ������������ �� ��������\n";
            std::system("pause");
            break;
        }
        case 9:
        {
            sort_skill_level(doctor_list, amount);
            std::cout << "������� ������������ �� ������� ������������\n";
            std::system("pause");
            break;
        }
        case 10:
        {
            delete_doctor(doctor_list, amount);
            std::system("pause");
            break;
        }
        case 11:
        {
            clean(doctor_list, amount);
            fileRead(doctor_list,amount);
            std::cout << "������ ����������� �� ����� ������\n";
            std::system("pause");
            break;
        }
        case 12:
        {
            
            fileWrite(doctor_list, amount);
            std::cout << "������ ����������� ������� � ����\n";
            std::system("pause");
            break;
        }
        default:
            std::cout << "������������ ����� ������ ����\n";
            break;
        }
    } while (punkt != 0);
    delete[] doctor_list;
    return 0;
}
