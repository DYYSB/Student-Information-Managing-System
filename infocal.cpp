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

void copyToSort(_STUDENT* p, int choice)
{
    std::vector<_STUDENT> data_arr;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        data_arr.push_back(*p);
    }
    sortBy(&data_arr, choice);
    std::cout << "Serial" << '\t' << "ID" << '\t' << "Name" << '\t' << "Birthday" << '\t' << "Sex" << '\t';
    std::cout << "Score1" << '\t' << "Score2" << '\t' << "Score3" << '\t' << "Score4" << '\t' << "Total" << std::endl;
    for (int i = 0; i < data_arr.size(); i++)
    {
        std::cout << i + 1 << ".\t" << data_arr.at(i).id << '\t' << data_arr.at(i).name << '\t';
        std::cout << data_arr.at(i).birth.year << '/' << data_arr.at(i).birth.month << '/' << data_arr.at(i).birth.day << '\t' << data_arr.at(i).sex << '\t';
        std::cout << data_arr.at(i).score1 << '\t' << data_arr.at(i).score2 << '\t' << data_arr.at(i).score3 << '\t' << data_arr.at(i).score4 << '\t';
        std::cout << data_arr.at(i).score1 + data_arr.at(i).score2 + data_arr.at(i).score3 + data_arr.at(i).score4 << std::endl;
    }
}

void sortBy(std::vector<_STUDENT>* data_arr, int choice)
{
    switch (choice)
    {
    case 0:
        for (int i = 0; i < data_arr->size() - 1; i++)
        {
            for (int j = 0; j < data_arr->size() - i - 1; j++)
            {
                if (data_arr->at(j).id > data_arr->at(j + 1).id)
                {
                    swapStu(data_arr, j, j + 1);
                }
            }
        }
        return;

    case 1:
        for (int i = 0; i < data_arr->size() - 1; i++)
        {
            for (int j = 0; j < data_arr->size() - i - 1; j++)
            {
                if (data_arr->at(j).score1 < data_arr->at(j + 1).score1)
                {
                    swapStu(data_arr, j, j + 1);
                }
            }
        }
        return;

    case 2:
        for (int i = 0; i < data_arr->size() - 1; i++)
        {
            for (int j = 0; j < data_arr->size() - i - 1; j++)
            {
                if (data_arr->at(j).score2 < data_arr->at(j + 1).score2)
                {
                    swapStu(data_arr, j, j + 1);
                }
            }
        }
        return;

    case 3:
        for (int i = 0; i < data_arr->size() - 1; i++)
        {
            for (int j = 0; j < data_arr->size() - i - 1; j++)
            {
                if (data_arr->at(j).score3 < data_arr->at(j + 1).score3)
                {
                    swapStu(data_arr, j, j + 1);
                }
            }
        }
        return;

    case 4:
        for (int i = 0; i < data_arr->size() - 1; i++)
        {
            for (int j = 0; j < data_arr->size() - i - 1; j++)
            {
                if (data_arr->at(j).score4 < data_arr->at(j + 1).score4)
                {
                    swapStu(data_arr, j, j + 1);
                }
            }
        }
        return;

    case 5:
        for (int i = 0; i < data_arr->size() - 1; i++)
        {
            for (int j = 0; j < data_arr->size() - i - 1; j++)
            {
                if ((data_arr->at(j).score1 + data_arr->at(j).score2 + data_arr->at(j).score3 + data_arr->at(j).score4) < (data_arr->at(j + 1).score1 + data_arr->at(j + 1).score2 + data_arr->at(j + 1).score3 + data_arr->at(j + 1).score4))
                {
                    swapStu(data_arr, j, j + 1);
                }
            }
        }
        return;
    }
}