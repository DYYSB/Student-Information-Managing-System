#include "infocal.h"

int calAverage(_STUDENT* p, int i)          //计算第i科的平均成绩，传入表头和i
{
    int j = 0;
    int sum = 0;
    switch (i)
    {
    case 1:
        do
        {
            p = p->next;
            sum += p->score1;
            j++;
        } while (p->next != NULL);
        return sum / j;

    case 2:
        do
        {
            p = p->next;
            sum += p->score2;
            j++;
        } while (p->next != NULL);
        return sum / j;

    case 3:
        do
        {
            p = p->next;
            sum += p->score3;
            j++;
        } while (p->next != NULL);
        return sum / j;

    case 4:
        do
        {
            p = p->next;
            sum += p->score4;
            j++;
        } while (p->next != NULL);
        return sum / j;

    default:
        return -1;
    }
}

double passRate(_STUDENT* p, int i)         //计算第i个学科的通过率，传入表头和i
{
    int j = 0;
    int sum = 0;
    double prate;
    switch (i)
    {
    case 1:
        do
        {
            p = p->next;
            if (p->score1 >= 60)
                sum++;
            j++;
        } while (p->next != NULL);
        prate = (double)sum / (double)j;
        return prate;

    case 2:
        do
        {
            p = p->next;
            if (p->score2 >= 60)
                sum++;
            j++;
        } while (p->next != NULL);
        prate = (double)sum / (double)j;
        return prate;

    case 3:
        do
        {
            p = p->next;
            if (p->score3 >= 60)
                sum++;
            j++;
        } while (p->next != NULL);
        prate = (double)sum / (double)j;
        return prate;

    case 4:
        do
        {
            p = p->next;
            if (p->score4 >= 60)
                sum++;
            j++;
        } while (p->next != NULL);
        prate = (double)sum / (double)j;
        return prate;

    default:
        return -1.0;
    }
}

_STUDENT* searchMinAge(_STUDENT* p)
{
    unsigned int max;
    _STUDENT* maxdate = p;
    if (p->next != NULL)
    {
        max = maxdate->birth.date;
    }
    do
    {
        p = p->next;
        if (max < p->birth.date)
        {
            max = p->birth.date;
            maxdate = p;
        }
    } while (p->next != NULL);
    return maxdate;
}