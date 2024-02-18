#include <locale.h>
#include <stdio.h>
#include "Header.h"
#include <iostream>

struct zakaz
{
    int nomer_zakaza;
    char nazvanie[20];
    int kol_vo;
    int stoimost_za_kg;
    int itog_stoimost;
    int nover_nakladnoi;
};

static zakaz sirio[20], temp[20];
int kolvo_zakazov;

extern void enter()
{
    FILE* file;
    if (fopen_s(&file, "order.txt", "a") != 0) {
        printf("ERROR");
        return;
    }
    printf("введите сколько заказов:");
    scanf_s("\n%d", &kolvo_zakazov);
    register int i;
    for (i = 0; i < kolvo_zakazov; i++)
    {
        printf("введите номер заказа:");
        scanf_s("\n%d", &sirio[i].nomer_zakaza);
        printf("введите название сырья:");
        scanf_s("\n%s", &sirio[i].nazvanie, 20);
        printf("введите количество кг  сырья:");
        scanf_s("\n%d", &sirio[i].kol_vo);
        printf("введите номер наклодной :");
        scanf_s("\n%d", &sirio[i].nover_nakladnoi);
        printf("введите стоимость сырья за кг:");
        scanf_s("\n%d", &sirio[i].stoimost_za_kg);
        sirio[i].itog_stoimost = sirio[i].kol_vo * sirio[i].stoimost_za_kg;
        fprintf(file, "%d %s %d %d %d %d\n", sirio[i].nomer_zakaza, sirio[i].nazvanie, sirio[i].kol_vo, sirio[i].stoimost_za_kg, sirio[i].nover_nakladnoi, sirio[i].itog_stoimost);
    }

    fclose(file);
}


extern void read()
{
    register int i;
    printf("--------------------------------------------------------------------------------------------\n");
    printf("| № | название | количество сырья | стоимость за кг | номер наклодной | итоговая стоимость |\n");
    printf("--------------------------------------------------------------------------------------------\n");
    for (i = 0; i < kolvo_zakazov; i++)
    {
        printf(" %d  %8s %14d %16d %16d %16d\n", sirio[i].nomer_zakaza, sirio[i].nazvanie, sirio[i].kol_vo, sirio[i].stoimost_za_kg, sirio[i].nover_nakladnoi, sirio[i].itog_stoimost);
        printf("--------------------------------------------------------------------------------------------\n");

    }
}




extern  void sort_po_naklodnoi()
{
    register int i, j;
    for (i = 1; i < kolvo_zakazov; i++)
    {
        for (j = kolvo_zakazov - 1; j >= i; j--)
        {
            if (sirio[j - 1].nover_nakladnoi > sirio[j].nover_nakladnoi)
            {
                temp[j] = sirio[j - 1];
                sirio[j - 1] = sirio[j];
                sirio[j] = temp[j];
            }
        }
    }

    //printf("отсортированные данные пономеру накладной :\n");
    //read();
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
}

//extern  void remote()


//extern  void edit();



extern void View() {
    FILE* file;
    if (fopen_s(&file, "order.txt", "r") != 0) {
        printf("ERROR");
        return;
    }

    printf("--------------------------------------------------------------------------------------------\n");
    printf("| № | название | количество сырья | стоимость за кг | номер наклодной | итоговая стоимость |\n");
    printf("--------------------------------------------------------------------------------------------\n");

    zakaz sirio;
    while (fread(&sirio, sizeof(zakaz), 1, file) == 2) {
        printf(" %d  %8s %14d %16d %16d %16d\n", sirio.nomer_zakaza, sirio.nazvanie, sirio.kol_vo, sirio.stoimost_za_kg, sirio.nover_nakladnoi, sirio.itog_stoimost);
        printf("--------------------------------------------------------------------------------------------\n");
    }

    fclose(file);
}
/*
extern void View()
{
    FILE* file;
    if (fopen_s(&file, "order.txt", "r") != 0) {
        printf("ERROR");
        return;
    }
    printf("Информация о заказах:\n");
    while (!feof(file)) {
        int nomer_zakaza, kol_vo, stoimost_za_kg, nover_nakladnoi, itog_stoimost;
        char nazvanie[20];
        if (fscanf_s(file, "%d %s %d %d %d %d", &nomer_zakaza, sizeof(nazvanie), &kol_vo, &stoimost_za_kg, &nover_nakladnoi, &itog_stoimost) == EOF) {
            break;
        }
        printf("Номер заказа: %d, Название сырья: %s, Количество кг сырья: %d, Стоимость сырья за кг: %d, Номер накладной: %d, Общая стоимость: %d\n",
            nomer_zakaza, nazvanie, kol_vo, stoimost_za_kg, nover_nakladnoi, itog_stoimost);
    }
    fclose(file);
}
*/