
#include <locale.h>
#include <stdio.h>
#include "Header.h"
#include <iostream>
//static char filename[] = "документ.txt";
struct zakaz
{
    int nomer_zakaza;
    char nazvanie[20];
    int kol_vo;
    int stoimost_za_kg;
    int itog_stoimost;
    int nover_nakladnoi;
};

//static int nomer_nakladnoi(int nover_nak)
//{
//    int nomer = 999999;
//    if (100000< nover_nak || nover_nak >nomer)
//    {
//        return 0;
//    }
//    return 1;
//}

static int Only_Letters(const char* str)
{
    while (*str) {
        if (isdigit(*str))
        {
            return 1;
        }
        str++;
    }
    return 0;
}
static zakaz sirio[20], temp[20];
int kolvo_zakazov;

extern void enter()
{
   /* FILE* file;
    if (fopen_s(&file, "документ.txt", "w") != 0)
    {
        printf("ERROR");
        return;
    }*/
    printf("Сколько закупок планируете сделать:");
    if (scanf_s("%d", &kolvo_zakazov) != 1)
    {
        printf("Ошибка: введите число.\n");
    }
    getchar();
    register int i;
    for (i = 0; i < kolvo_zakazov; i++)
    {
       
        while (1)
        {
            printf("Введите номер закупки: ");
            if (scanf_s("%d", &sirio[i].nomer_zakaza) != 1) 
            {
                printf("Ошибка: введите число.\n");
               while (getchar() != '\n'); 
            }
            else 
            {
                break;
            }
        }
        while (1)
        {
             printf("Введите название:");
             scanf_s("\n%s", &sirio[i].nazvanie, 20);
             if (Only_Letters(sirio[i].nazvanie))
             {
                 printf("Вы ввели число. Пожалуйста, введите строку, которая не является числом.");
                 while (getchar() != '\n');
             }
             else
             {
               break;
             }
        }
        while (1)
        {
            printf("Введите сколько кг :");
            if (scanf_s("%d", &sirio[i].kol_vo) != 1)
            {
                printf("Ошибка: введите число.\n");
                while (getchar() != '\n'); 
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            printf("Введите номер наклодной :");
            if (scanf_s("%d", &sirio[i].kol_vo) != 1)
            {
                printf("Ошибка: введите число.\n");
                while (getchar() != '\n');
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            printf("Введите стоимость за кг:");
            if (scanf_s("%d", &sirio[i].stoimost_za_kg) != 1)
            {
                printf("Ошибка: введите число.\n");
                while (getchar() != '\n');
            }
            else
            {
                break;
            }
         }
        sirio[i].itog_stoimost = sirio[i].kol_vo * sirio[i].stoimost_za_kg;
        //fprintf(file, "%d %s %d %d %d %d\n", sirio[i].nomer_zakaza, sirio[i].nazvanie, sirio[i].kol_vo, sirio[i].stoimost_za_kg, sirio[i].nover_nakladnoi, sirio[i].itog_stoimost);
    
    }

    //fclose(file);
}


extern void read()
{
    register int i;
    printf("--------------------------------------------------------------------------------------------\n");
    printf("| № | название | количество сырья | стоимость за кг | номер наклодной | итоговая стоимость  |\n");
    printf("--------------------------------------------------------------------------------------------\n");
    for (i = 0; i < kolvo_zakazov; i++)
    {
        printf(" %d  %8s %14d %16d %16d %16d\n", sirio[i].nomer_zakaza, sirio[i].nazvanie, sirio[i].kol_vo, sirio[i].stoimost_za_kg, sirio[i].nover_nakladnoi, sirio[i].itog_stoimost);
        printf("--------------------------------------------------------------------------------------------\n");

    }
}

extern  void sort_po_naklodnoi()
{
    FILE* file;
    if (fopen_s(&file, "документ.txt", "a") != 0)
    {
        printf("Не удалось открыть файл");
        return;
    }
    register int i, j;
    for (i = 1; i < kolvo_zakazov; i++)
    {
        for (j = kolvo_zakazov - 1; j >= i; j--)
        {
            if (sirio[j - 1].nover_nakladnoi > sirio[j].nover_nakladnoi)
            {
                temp[j].nover_nakladnoi = sirio[j - 1].nover_nakladnoi;
                sirio[j - 1].nover_nakladnoi = sirio[j].nover_nakladnoi;
                sirio[j].nover_nakladnoi = temp[j].nover_nakladnoi;
            }
        }
        
    }
    printf("Данные после сортировки:\n");
    read();
    write_file();
    fclose(file);
}


extern  void sort_po_nazvanii()
{
    register int i, j;
    for (i = 1; i < kolvo_zakazov; i++)
    {
        for (j = kolvo_zakazov - 1; j >= i; j--)
        {
            if (strcmp(sirio[j - 1].nazvanie, sirio[j].nazvanie) > 0)
            {
                temp[j] = sirio[j - 1];
                sirio[j - 1] = sirio[j];
                sirio[j] = temp[j];
            }
        }
    }
    printf("Данные после сортировки:\n");
    read();
    write_file();
}

extern  void remote()
{
    register int number;
    printf("Введите номер сырья, который хотите удалить: ");
    while (1)
    {
        if (scanf_s("%d", &number) != 1)
        {
            printf("Ошибка: введите число.\n");
            while (getchar() != '\n'); 
        }
        else
        {
            break;
        }
    }
    int poisk_dannih = 0;
    for (int i = 1; i < kolvo_zakazov; i++)
    {
        if (sirio[i].nomer_zakaza == sirio[number].nomer_zakaza)
        {
            poisk_dannih= 1;
            for (int j = i; j < kolvo_zakazov - 1; j++)
            {
                sirio[j] = sirio[j + 1];
            }
            kolvo_zakazov--;
        }
    }
    if (poisk_dannih ==0)
    {
        printf("Сырья с номером %d не найдено.\n", number);
    }
    write_file();
}


extern  void edit()
{
    int choise;
    int number;
    printf("Введите номер заказа, который хотите отредактировать: ");
    while (1)
    {
        if (scanf_s("%d", &number) != 1)
        {
            printf("Ошибка: введите число.\n");
            while (getchar() != '\n'); 
        }
        else
        {
            break;
        }
    }
    int poisk_dannih = 0;
    for (int i = 0; i < kolvo_zakazov; i++)
    {
        if (sirio[i].nomer_zakaza == number)
        {
            poisk_dannih = 1;
            do
            {
                printf("\n1.Изменить название.\n");
                printf("2.Изменить количество кг сырья.\n");
                printf("3.Изменить номер накладной\n");
                printf("4.Изменить стоимость сырья за кг.\n");
                printf("5.Изменить все данные.\n");
                printf("6.Ввыйти из меню.\n");
                printf("Введите ваш выбор : ");
                scanf_s("%d", &choise);
                switch (choise)
                {
                case 1: 
                    while (1)
                    {
                        printf("Новое название сырья: ");
                        scanf_s("%s", &sirio[i].nazvanie, 20);
                        if (Only_Letters(sirio[i].nazvanie))
                        {
                            printf("Вы ввели число. Пожалуйста, введите строку, которая не является числом.");
                            while (getchar() != '\n');
                        }
                        else
                        {
                            break;
                        }
                    }
                    break;
                case 2:
                    while (1)
                    {
                        printf("Новое количество кг сырья: ");
                        if (scanf_s("%d", &sirio[i].kol_vo) != 1)
                        {
                            printf("Ошибка: введите число.\n");
                            while (getchar() != '\n'); 
                        }
                        else
                        {
                        break;
                        }
                        
                    }
                        sirio[i].itog_stoimost = sirio[i].kol_vo * sirio[i].stoimost_za_kg;
                        break;
                    
                case 3:  
                    while (1)
                    {
                        printf("Новый номер накладной: ");
                        if (scanf_s("%d", &sirio[i].kol_vo) != 1)
                        {
                            printf("Ошибка: введите число.\n");
                            while (getchar() != '\n'); 
                        }
                        else
                        {
                            break;
                        }
                    }
                    break;
                case 4: 
                    while (1)
                    {
                        printf("Новая стоимость сырья за кг: ");
                        if (scanf_s("%d", &sirio[i].stoimost_za_kg) != 1)
                        {
                            printf("Ошибка: введите число.\n");
                            while (getchar() != '\n'); 
                        }
                        else
                        {
                            break;
                        }
                    }
                    sirio[i].itog_stoimost = sirio[i].kol_vo * sirio[i].stoimost_za_kg;
                    break;
                case 5: printf("Введите новые данные для заказа %d:\n", number);
                  
                    while (1)
                    {
                        printf("Новое название сырья: ");
                        scanf_s("%s", &sirio[i].nazvanie, 20);
                        if (Only_Letters(sirio[i].nazvanie))
                        {
                            printf("Вы ввели число. Пожалуйста, введите строку, которая не является числом.");
                            while (getchar() != '\n');
                        }
                        else
                        {
                            break;
                        }
                    }
                    while (1)
                    {
                        printf("Новое количество кг сырья: ");
                        if (scanf_s("%d", &sirio[i].kol_vo) != 1)
                        {
                            printf("Ошибка: введите число.\n");
                            while (getchar() != '\n'); 
                        }
                        else
                        {
                            break;
                        }
                    }
                    while (1)
                    {
                        printf("Новый номер накладной: ");
                        if (scanf_s("%d", &sirio[i].nover_nakladnoi) != 1)
                        {
                            printf("Ошибка: введите число.\n");
                            while (getchar() != '\n'); 
                        }
                        else
                        {
                            break;
                        }
                    }
                    while (1)
                    {
                        printf("Новая стоимость сырья за кг: ");
                        if (scanf_s("%d", &sirio[i].stoimost_za_kg) != 1)
                        {
                            printf("Ошибка: введите число.\n");
                            while (getchar() != '\n'); 
                        }
                        else
                        {
                            break;
                        }
                    }
                    sirio[i].itog_stoimost = sirio[i].kol_vo * sirio[i].stoimost_za_kg;
                    printf("Данные для сырья %d изменены.\n", number);
                    break;

                case 6:  printf("досвидание\n");
                         write_file();
                    return;
                }
            } while (choise != 6);
            return;
        }
    }
    if (poisk_dannih==0) {
        printf("Сырьё с номером %d не найдено.\n", number);
    }
    
}

extern void file()
{
    FILE* file;
    char filename[] = "документ.txt";
    if (fopen_s(&file, "документ.txt", "r") != 0)
    {
        printf("Не удалось открыть файл %s\n", filename);
        return;
    }
    kolvo_zakazov = 0;
    while (kolvo_zakazov < 11 && fscanf_s(file, "%d %s %d %d %d %d", &sirio[kolvo_zakazov].nomer_zakaza, sirio[kolvo_zakazov].nazvanie, 20, &sirio[kolvo_zakazov].kol_vo, &sirio[kolvo_zakazov].stoimost_za_kg, &sirio[kolvo_zakazov].nover_nakladnoi, &sirio[kolvo_zakazov].itog_stoimost) == 6)
    {
        kolvo_zakazov++;
    }
    fclose(file);
    read();
}

extern void write_file()
{
    FILE* file;
    char filename[] = "измененные_данные.txt"; 
    if (fopen_s(&file, "измененные_данные.txt", "w") != 0) 
    { 
        printf("Не удалось открыть файл %s\n", filename);
        return;
    }
    for (int i = 0; i < kolvo_zakazov; i++) 
    {
        fprintf(file, "%d %s %d %d %d %d\n", sirio[i].nomer_zakaza, sirio[i].nazvanie, sirio[i].kol_vo, sirio[i].stoimost_za_kg, sirio[i].nover_nakladnoi, sirio[i].itog_stoimost);
    }
    fclose(file); 
    printf("Измененные данные успешно сохранены в файл %s\n", filename);
}