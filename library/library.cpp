#include "DoctorList.h"

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Doctor* doctor_list = new Doctor[quantity];
    int amount = 0; // Реальное колличество элеметов
    int punkt = 1; // Пункт меню
    do
    {
        std::system("cls");
        std::cout << "Выберите необходимое действие:\n" <<
            "1. Очистка списка\n" <<
            "2. Добавить сотрудка клиники\n" <<
            "3. Вывести сотрудников клиники\n" << 
            "4. Вывести сотрудника по порядковому номеру\n" <<
            "5. Редактироование данных сотрудника\n" <<
            "6. Найти сотрудника по фамилии\n" <<
            "7. Найти по уровню квалификации\n" <<
            "8. Отсортировать список по фамилии\n" <<
            "9. Отсортировать список по квалификации\n"<<
            "10.Удаление сотрудника из списка\n" <<
            "11.Ввод списка из файла\n" <<
            "12.Вывод списка в файл\n" <<
            "0. Закончить работу\n";
        punkt = input_int("Введите номер пункта меню: \n", 0, 12);
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
            int num = input_int("Введите номер сотрудника, которого хотите вывести\n", 1, amount) - 1;
            std::cout << "Номер сотрудника: " << num + 1 << '\n';
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
            std::cout << "Введите фамилию\n";
            std::cin >> surname_; //getline()
            int count = 0, i = 0;
            Doctor* Seach = new Doctor[quantity];
            // вывести на экран данные доктора по указателю, не добавляя в новый список
            while (count <= amount)
            {
                search_surname(surname_, doctor_list, amount, &count);
                if (count <= amount) Seach[i++] = doctor_list[count++];
            }
            if (i == 0) std::cout << "Данная фамилия не найдена\n";
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
            std::cout << "Введите уровень квалификации\n";
            std::cin >> skill_level_;
            int count = 0, i = 0;
            Doctor* Seach = new Doctor[quantity];
            while (count <= amount)
            {
                search_skill_level(skill_level_, doctor_list, amount, &count);
                if (count <= amount) Seach[i++] = doctor_list[count++];
            }
            if (i == 0) std::cout << "Не найдены сотрудники с такой квалификацией\n";
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
            std::cout << "Каталог отсортирован по фамилиям\n";
            std::system("pause");
            break;
        }
        case 9:
        {
            sort_skill_level(doctor_list, amount);
            std::cout << "Каталог отсортирован по уровеню квалификации\n";
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
            std::cout << "Список сотрудников из файла сделан\n";
            std::system("pause");
            break;
        }
        case 12:
        {
            
            fileWrite(doctor_list, amount);
            std::cout << "Список сотрудников записан в файл\n";
            std::system("pause");
            break;
        }
        default:
            std::cout << "Неправильный выбор пункта меню\n";
            break;
        }
    } while (punkt != 0);
    delete[] doctor_list;
    return 0;
}
