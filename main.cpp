#include <locale.h>
#include <stdio.h>
#include "Header.h"
#include <iostream>

int main()
{
    extern int kolvo_zakazov;
    setlocale(LC_ALL, "Rus");
    int choise;
    do
    {

        printf("\n1.ввести данные сырья.\n");
        printf("2.Просмотреть введенные данные сырья.\n");
        printf("3.сортировать по наклодной \n");
        printf("4.сортировать по названию сырья.\n");
        printf("5.Редактировать данные.\n");
        printf("6.Удалить какое-нибудь сырьё.\n");
        printf("7.Открыть данные из файла.\n");
        printf("8.Выйти из программы.\n");
        printf("Введите ваш выбор: ");
        scanf_s("%d", &choise);
        switch (choise)
        {
        case 1: enter();
            break;
        case 2: read();
            break;
        case 3: sort_po_naklodnoi();
            break;
        case 4:  sort_po_nazvanii();
            break;
        case 5: edit(); 
            break;
        case 6: remote();
            break;
        case 7:  file();
            break;
        case 8:  printf("досвидание ");
            return 0;
        }
    } while (choise != 8);
    return 0;
}