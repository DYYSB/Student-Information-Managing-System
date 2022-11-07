#pragma once
#include <string>
#include <iostream>
#include <fstream>

enum sextype { man, woman };   //ö������
typedef struct student
{
    union birthdate
    {
        unsigned int date = 0;
        struct
        {
            unsigned int day : 5;
            unsigned int month : 4;

            unsigned int year : 12;
        };
    } birth;
    //�ù�����+λ������ʾ�������ڣ��Լ����ڴ�ռ�á�
    int id;
    std::string name;
    sextype sex;
    int score1;
    int score2;
    int score3;
    int score4;
    student* next;
} _STUDENT;

_STUDENT* createHead();
_STUDENT* createNode(int, std::string, _STUDENT::birthdate, sextype, int, int, int, int);
_STUDENT* createData();
void outputNode(_STUDENT*);
_STUDENT* searchNode(_STUDENT*, std::string);
_STUDENT* readFromFile();
void writeToFile(_STUDENT*);
void addToNode(_STUDENT*, int, std::string, _STUDENT::birthdate, sextype, int, int, int, int);