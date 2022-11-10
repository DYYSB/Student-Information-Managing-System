#include "sort.h"

void swapStu(std::vector<_STUDENT>* data_arr, int i, int j)
{
    swapInt(&data_arr->at(i).id, &data_arr->at(j).id);

    std::string name = data_arr->at(i).name;
    data_arr->at(i).name = data_arr->at(j).name;
    data_arr->at(j).name = name;

    _STUDENT::birthdate birth;
    birth.date = data_arr->at(i).birth.date;
    data_arr->at(i).birth.date = data_arr->at(j).birth.date;
    data_arr->at(j).birth.date = birth.date;

    sextype sex = data_arr->at(i).sex;
    data_arr->at(i).sex = data_arr->at(j).sex;
    data_arr->at(j).sex = sex;

    swapInt(&data_arr->at(i).score1, &data_arr->at(j).score1);
    swapInt(&data_arr->at(i).score2, &data_arr->at(j).score2);
    swapInt(&data_arr->at(i).score3, &data_arr->at(j).score3);
    swapInt(&data_arr->at(i).score4, &data_arr->at(j).score4);
}

void swapInt(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
