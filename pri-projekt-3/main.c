#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.h"
int main()
{
    struct stos *top=NULL, *wskaznik;
    wskaznik = (struct stos*) malloc(sizeof(struct stos));
    struct element data;
    struct kolejka *head, *tail, *temp;
    temp=(struct kolejka*) malloc(sizeof(struct kolejka));
    struct element2 data2;
    head = tail = NULL;
    int kolejka=0, i=0, rozmiar=0, ilosc_poz=rozmiar, los_prawd=0, k=1, komenda=0, warunek=0, petla1=0, petla2=0;
    puts("Czy chcesz odczytac dane z pliku? (0-nie|1-tak)");
    int decyzja=0;
    warunek=0;
    while(warunek==0)
    {
        if(scanf("%d", &decyzja)!=1) puts("Blad! Jeszcze raz!");
        else
        {
            if(decyzja==0) warunek=1;
            else if(decyzja==1)
            {
                FILE * plik;
                puts("Podaj nazwe pliku");
                char nazwa[50];
                scanf("%s", &nazwa);
                if ((plik = fopen(nazwa, "rb")) == NULL) printf("Blad otwarcia pliku. Jeszcze raz.\nCzy chcesz odczytac dane z pliku? (0-nie|1-tak)\n");
                else
                {
                    fseek(plik, 0L, SEEK_SET);
                    fread(&rozmiar, sizeof(int), 1, plik);
                    ilosc_poz=rozmiar;
                    for(ilosc_poz; ilosc_poz>0;ilosc_poz--)
                    {
                        data.prawd=rand()%101;
                        top=push(top, data);
                    }
                    ilosc_poz=rozmiar;
                    wskaznik=top;
                    for(ilosc_poz;ilosc_poz>0;ilosc_poz--)
                    {
                        fread(&wskaznik->data.prawd, sizeof(int), 1, plik);
                        wskaznik=wskaznik->next;
                    }
                    fread(&kolejka, sizeof(int), 1, plik);
                    k=kolejka;
                    for(k; k>0; k--)
                    {
                        fread(&data2.numer, sizeof(int), 1, plik);
                        fread(&data2.kolor, sizeof(int), 1, plik);
                        if (kolejka==k) head = tail = Insert(tail, data2);
                        else tail = Insert(tail, data2);
                    }
                    fread(&i, sizeof(int), 1, plik);
                    fclose(plik);
                    puts("Odczytano");
                    warunek=1;
                }
            }
            else puts("Nie ma takiej komendy! Jeszcze raz!");
        }
        while(getchar()!='\n');
    }
    puts("Z ilu segmentow ma sie skladac wieza?");
    warunek=0;
    while(warunek==0)
    {
        if(scanf("%d", &petla1)!=1) puts("Blad! Jeszcze raz!");
        else
        {
            for(petla2=1; petla2<=petla1; petla2++)
            {
                data.prawd=rand()%101;
                top=push(top, data);
                rozmiar++;
            }
            warunek=1;
        }
        while(getchar()!='\n');
    }
    puts("Ile wrzucic kulek?");
    warunek=0;
    while(warunek==0)
    {
        if(scanf("%d", &petla1)!=1) puts("Blad! Jeszcze raz!");
        else
        {
            for(petla2=1; petla2<=petla1; petla2++)
            {
                if(rozmiar==0) puts("Stos jest pusty!");
                else
                {
                    data2.numer=i;
                    i++;
                    data2.kolor=0;
                    while(data2.kolor==0)
                    {
                        data2.kolor=rand()%6;
                    }
                    ilosc_poz=rozmiar; los_prawd=0;
                    wskaznik=top;
                    for(ilosc_poz;ilosc_poz>0;ilosc_poz--)
                    {
                        if(ilosc_poz==1)
                        {
                            data2.kolor=0;
                            puts("Kulka spadla na poziom 0 - zostala zniszczona");
                            break;
                        }
                        else
                        {
                            los_prawd=rand()%101;
                            if(los_prawd>wskaznik->data.prawd)
                            {
                                printf("Kulka spadla na poziom %d\n", (ilosc_poz-1));
                                if (kolejka==0) head = tail = Insert(tail, data2);
                                else tail = Insert(tail, data2);
                                kolejka++;
                                break;
                            }
                            else
                            {
                                wskaznik=wskaznik->next;
                            }
                        }
                    }
                }
            }
            warunek=1;
        }
        while(getchar()!='\n');
    }
    puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
    while(1)
    {
        k=1; komenda=0;
        while(k==1)
        {
            if(scanf("%d", &komenda)==1)
            {
                if(getchar()!='\n')
                {
                    while(getchar()!='\n');
                    puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
                }
                else k=0;
            }
            else
            {
                while(getchar()!='\n');
                puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
            }
        }
        if(komenda==1)
        {
            data.prawd=rand()%101;
            top=push(top, data);
            rozmiar++;
            puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
        }
        else
        {
            if(komenda==2)
            {
                top=pop(top);
                if (rozmiar>0) rozmiar--;
                puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
            }
            else
            {
                if(komenda==3)
                {
                    if(rozmiar==0) puts("Stos jest pusty!");
                    else
                    {
                    data2.numer=i;
                    i++;
                    data2.kolor=0;
                    while(data2.kolor==0)
                    {
                        data2.kolor=rand()%6;
                    }
                    ilosc_poz=rozmiar; los_prawd=0;
                    wskaznik=top;
                    for(ilosc_poz;ilosc_poz>0;ilosc_poz--)
                    {
                        if(ilosc_poz==1)
                        {
                            data2.kolor=0;
                            puts("Kulka spadla na poziom 0 - zostala zniszczona");
                            break;
                        }
                        else
                        {
                            los_prawd=rand()%101;
                            if(los_prawd>wskaznik->data.prawd)
                            {
                                printf("Kulka spadla na poziom %d\n", (ilosc_poz-1));
                                if (kolejka==0) head = tail = Insert(tail, data2);
                                else tail = Insert(tail, data2);
                                kolejka++;
                                break;
                            }
                            else
                            {
                                wskaznik=wskaznik->next;
                            }
                        }
                    }
                    }
                    puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
                }
                else
                {
                    if(komenda==4)
                    {
                        if(kolejka==0)
                        {
                            puts("Nie ma kulek!");
                        }
                        else
                        {
                            if(rozmiar==0) puts("Stos jest pusty!");
                            else
                            {
                            data2=head->data2;
                            head=Remove(head);
                            kolejka--;
                            wskaznik=top;
                            ilosc_poz=rozmiar; los_prawd=0;
                            for(ilosc_poz;ilosc_poz>0;ilosc_poz--)
                            {
                                if(ilosc_poz==1)
                                {
                                    puts("Kulka spadla na poziom 0 - zostala zniszczona");
                                    break;
                                }
                                else
                                {
                                    los_prawd=rand()%101;
                                    if(los_prawd>wskaznik->data.prawd)
                                    {
                                        printf("Kulka spadla na poziom %d\n", (ilosc_poz-1));
                                        if (kolejka==0) head = tail = Insert(tail, data2);
                                        else tail = Insert(tail, data2);
                                        kolejka++;
                                        break;
                                    }
                                    else
                                    {
                                        wskaznik=wskaznik->next;
                                    }
                                }
                            }
                            }
                        }
                        puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
                    }
                    else
                    {
                        if(komenda==5)
                        {
                            if(kolejka==0)
                            {
                                puts("Nie ma kulek!");
                            }
                            else
                            {
                                head=Remove(head);
                                kolejka--;
                            }
                            puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
                        }
                        else
                        {
                            if(komenda==6)
                            {
                                if(rozmiar==0) puts("Stos jest pusty!");
                                else printf("Ilosc segmentow wiezy: %d\n", rozmiar);
                                if(kolejka==0) puts("Nie ma kulek!");
                                else
                                {
                                    puts("Zawartosc kolejki (numer, kolor):");
                                    temp=head;
                                    while(temp!=NULL)
                                    {
                                        printf("%d, ", temp->data2.numer);
                                        switch (temp->data2.kolor)
                                        {
                                            case 1:
                                                printf("bialy\n");
                                                break;
                                            case 2:
                                                printf("czarny\n");
                                                break;
                                            case 3:
                                                printf("niebieski\n");
                                                break;
                                            case 4:
                                                printf("zielony\n");
                                                break;
                                            default:
                                                printf("czerwony\n");
                                                break;
                                        }
                                        temp=temp->nast;
                                    }
                                }
                                puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
                            }
                            else
                            {
                                if(komenda==7)
                                {
                                    puts("Czy chcesz zapisac dane do pliku? (0-nie|1-tak)");
                                    decyzja=0;
                                    warunek=0;
                                    while(warunek==0)
                                    {
                                        if(scanf("%d", &decyzja)!=1) puts("Blad! Jeszcze raz!");
                                        else
                                        {
                                            if(decyzja==0) return 0;
                                            else if(decyzja==1)
                                            {
                                                FILE *plik;
                                                if ((plik = fopen("dane.bin", "wb")) == NULL)
                                                {
                                                    printf("Blad otwarcia pliku\n");
                                                    return 0;
                                                }
                                                else
                                                {
                                                    fseek(plik, 0L, SEEK_SET);
                                                    fwrite(&rozmiar, sizeof(int), 1, plik);
                                                    ilosc_poz=rozmiar;
                                                    wskaznik=top;
                                                    for(ilosc_poz;ilosc_poz>0;ilosc_poz--)
                                                    {
                                                        fwrite(&wskaznik->data.prawd, sizeof(int), 1, plik);
                                                        wskaznik=wskaznik->next;
                                                    }
                                                    fwrite(&kolejka, sizeof(int), 1, plik);
                                                    temp=head;
                                                    while(temp!=NULL)
                                                    {
                                                        fwrite(&temp->data2.numer, sizeof(int), 1, plik);
                                                        fwrite(&temp->data2.kolor, sizeof(int), 1, plik);
                                                        temp=temp->nast;
                                                    }
                                                    fwrite(&i, sizeof(int), 1, plik);
                                                    fclose(plik);
                                                    puts("Zapisano");
                                                    return 0;
                                                }
                                            }
                                            else puts("Nie ma takiej komendy! Jeszcze raz!");
                                        }
                                        while(getchar()!='\n');
                                    }
                                }
                                else puts("1-dodaj segment|2-usun segment|3-wrzuc nowa kulke|4-wrzuc kulke jeszcze raz|5-zniszcz kulke|6-podglad danych|7-koniec");
                            }
                        }
                    }
                }
            }
        }
    }
}
