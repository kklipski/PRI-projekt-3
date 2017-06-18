#ifndef FUNKCJE_H
#define FUNKCJE_H
struct element2
{
    int numer, kolor;
};
struct kolejka
{
    struct element2 data2;
    struct kolejka *nast;
};
struct element
{
    int prawd;
};
struct stos
{
    struct element data;
    struct stos *next;
};
struct kolejka *Insert(struct kolejka *tail, struct element2 data2);
struct kolejka *Remove(struct kolejka *head);
struct stos *push(struct stos *top, struct element data);
struct stos *pop(struct stos *top);
#endif // FUNKCJE_H
