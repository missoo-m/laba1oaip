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

        printf("\n1.Ввести данные сырья.\n");
        printf("2.Просмотреть введённые данные .\n");
        printf("3.Отсортировать по номеру накладной \n");
        printf("4.Отсортировать по названію сырья.\n");
        printf("5.удалить какой-нибудь элемент.\n");
        printf("6.редактировать данные.\n");
        printf("7.Закрыть программу.\n");
        printf("Введите ваш выбор : ");
        scanf_s("%d", &choise);
        switch (choise)
        {
        case 1: enter();
            break;
        case 2: read();
            break;
        case 3:sort_po_naklodnoi;
            break;
        case 4:  sort_po_nazvanii;
            break;
        case 5: View();//remote();
            break;
        case 6:  //edit();
            break;
        case 7:  printf("досвидание");
            break;
        }
    } while (choise != 7);
    return 0;
}