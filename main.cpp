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

        printf("\n1.������ ������ �����.\n");
        printf("2.����������� �������� ������ .\n");
        printf("3.������������� �� ������ ��������� \n");
        printf("4.������������� �� ������� �����.\n");
        printf("5.������� �����-������ �������.\n");
        printf("6.������������� ������.\n");
        printf("7.������� ���������.\n");
        printf("������� ��� ����� : ");
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
        case 7:  printf("����������");
            break;
        }
    } while (choise != 7);
    return 0;
}