#define _CRT_SECURE_NO_WARNINGS     //防止scanf报错
#include <iostream>
#include <cstdio>
#include <string>
#include "node.h"
#include "infocal.h"

void outputHello()
{
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "         Student Information Management System" << std::endl;
    std::cout << std::endl;
    std::cout << "              1.Input information" << std::endl << std::endl;
    std::cout << "              2.Read information from file" << std::endl << std::endl;
    std::cout << "              3.Show information" << std::endl << std::endl;
    std::cout << "              4.Write information to file" << std::endl << std::endl;
    std::cout << "              5.Add information" << std::endl << std::endl;
    std::cout << "              6.Sort by ID" << std::endl << std::endl;
    std::cout << "              7.Sort by particular score/total score" << std::endl << std::endl;
    std::cout << "              8.Search by name" << std::endl << std::endl;
    std::cout << "              9.Search the youngest" << std::endl << std::endl;
    std::cout << "             10.Calculate average score and pass rate" << std::endl << std::endl;
    std::cout << "             11.Exit" << std::endl << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Please input your choice:  ";
}

int main()
{
    int choice;
    _STUDENT* head = NULL;
    while (1)
    {
        system("cls");
        outputHello();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");          //这一行是windows的清屏命令，在linux上使用请手动改动
            head = createData();
            std::cout << "Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            break;

        case 2:
            system("cls");
            head = readFromFile();
            std::cout << "Read successfully. Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            break;

        case 3:
            system("cls");
            if (head != NULL && head->next != NULL)
            {
                outputNode(head);
            }
            else
            {
                std::cout << "It seems that you haven't entered any data." << std::endl;
            }
            std::cout << "Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            break;

        case 4:
            system("cls");
            if (head != NULL && head->next != NULL)
            {
                writeToFile(head);
                std::cout << "Information has been written to \"student_info.txt\". Press any key to continue...";
                std::cin.ignore();
                std::cin.get();
            }
            else
            {
                std::cout << "It seems that you haven't entered any data." << std::endl;
            }
            break;

        case 5:
        {
            system("cls");
            _STUDENT* p;
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            int id;
            std::string name;
            _STUDENT::birthdate birth;
            unsigned year;
            unsigned month;
            unsigned day;
            sextype sex;
            int score1;
            int score2;
            int score3;
            int score4;
            char separate;
            std::cout << "Input student's ID, name, birth date, sex(0 is man, 1 is woman), score1, score2, score3, score4 like this:" << std::endl;
            std::cout << "000 dyy 1970/1/1 0 100 100 100 100" << std::endl << std::endl;
            std::cin >> id >> name >> year >> separate >> month >> separate >> day;
            std::scanf("%d", &sex);
            std::cin >> score1 >> score2 >> score3 >> score4;
            birth.day = day;
            birth.month = month;
            birth.year = year;
            addToNode(p, id, name, birth, sex, score1, score2, score3, score4);
            std::cout << "Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            break;
        }

        case 6:
            system("cls");
            std::cout << "Note that this will not make changes to the original sort of information." << std::endl;
            std::cout << "Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            copyToSort(head, 0);
            std::cout << "Press any key to continue...";
            //std::cin.ignore();
            std::cin.get();
            break;

        case 7:
            system("cls");
            int choice2;
            std::cout << "Which score would you like the information to be sorted by?" << std::endl;
            std::cout << "Use 1 to indicate score1, 2 to indicate score2, etc., and 5 to indicate total score." << std::endl;
            std::cin >> choice2;
            std::cout << "Note that this will not make changes to the original sort of information." << std::endl;
            std::cout << "Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            copyToSort(head, choice2);
            std::cout << "Press any key to continue...";
            //std::cin.ignore();
            std::cin.get();
            break;

        case 8:
        {
            system("cls");
            if (head != NULL && head->next != NULL)
            {
                std::string stuname;
                std::cout << "Input the student's name: " << std::endl;
                std::cin >> stuname;
                _STUDENT* sname = searchNode(head, stuname);
                if (sname != NULL)
                {
                    std::cout << sname->id << ' ' << sname->name << ' ' << sname->birth.year << '/' << sname->birth.month << '/' << sname->birth.day << ' ';
                    std::cout << sname->sex << ' ' << sname->score1 << ' ' << sname->score2 << ' ' << sname->score3 << ' ' << sname->score4 << std::endl;
                    std::cout << "Press any key to continue...";
                    std::cin.ignore();
                    std::cin.get();
                }
                else
                {
                    std::cout << "Student not found!" << std::endl;
                    std::cout << "Press any key to continue...";
                    std::cin.ignore();
                    std::cin.get();
                }
            }
            else
            {
                std::cout << "It seems that you haven't entered any data." << std::endl;
                std::cout << "Press any key to continue...";
                std::cin.ignore();
                std::cin.get();
            }
            break;
        }
            
        case 9:
            system("cls");
            if (head != NULL && head->next != NULL)
            {
                _STUDENT* minage = searchMinAge(head);
                std::cout << minage->id << ' ' << minage->name << ' ' << minage->birth.year << '/' << minage->birth.month << '/' << minage->birth.day << ' ';
                std::cout << minage->sex << ' ' << minage->score1 << ' ' << minage->score2 << ' ' << minage->score3 << ' ' << minage->score4 << std::endl;
            }
            else
            {
                std::cout << "It seems that you haven't entered any data." << std::endl;
            }
            std::cout << "Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            break;

        case 10:
            system("cls");
            if (head != NULL && head->next != NULL)
            {
                std::cout << "Please input the number of subject you want to calculate: ";
                int i;
                std::cin >> i;
                std::cout << "The average score is " << calAverage(head, i) << ", the pass rate is " << passRate(head, i) << "." << std::endl;
            }
            else
            {
                std::cout << "It seems that you haven't entered any data." << std::endl;
            }
            std::cout << "Press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            break;

        case 11:
        {
            if (head != NULL && head->next != NULL)
            {
                _STUDENT* p = head->next;
                _STUDENT* r = head;
                while (p->next != NULL)
                {
                    free(r);
                    r = p;
                    p = p->next;
                }
            }
            return 0;
        }

        default:
        {
            std::cout << "Invalid input!" << std::endl << "Press any key to continue..." << std::endl;
            std::cin.ignore();
            std::cin.get();
        }  
        }
    }
}