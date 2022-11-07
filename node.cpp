#define _CRT_SECURE_NO_WARNINGS
#include "node.h"

_STUDENT* createHead()      //创建链表头
{
    _STUDENT* head = new _STUDENT;
    head->id = 0;
    head->name = "0";
    head->score1 = 0;
    head->score2 = 0;
    head->score3 = 0;
    head->score4 = 0;
    head->sex = man;
    head->birth.date = 0;
    head->next = NULL;
    return head;
}

_STUDENT* createNode(int id, std::string name, _STUDENT::birthdate birth, sextype sex, int score1, int score2, int score3, int score4)
//创建链表结点，即每一个学生的信息
{
    _STUDENT* mid = new _STUDENT;
    mid->id = id;
    mid->birth = birth;
    mid->name = name;
    mid->sex = sex;
    mid->score1 = score1;
    mid->score2 = score2;
    mid->score3 = score3;
    mid->score4 = score4;
    mid->next = NULL;
    return mid;
}

_STUDENT* createData()
{
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
    //bool flag = false;
    _STUDENT* head = createHead();
    _STUDENT* p = head;
    _STUDENT* r = head;
    std::cout << "Please input students' data until you input -1." << std::endl;
    std::cout << "Input student's ID, name, birth date, sex(0 is man, 1 is woman), score1, score2, score3, score4 like this:" << std::endl;
    std::cout << "000 dyy 1970/1/1 0 100 100 100 100" << std::endl << std::endl;
    std::cin >> id;
    while (id != -1)
    {
        //std::scanf("%s %u/%u/%u %d %d %d %d %d", &name, &year, &month, &day, &sex, &score1, &score2, &score3, &score4);
        std::cin >> name >> year >> separate >> month >> separate >> day;
        std::scanf("%d", &sex);
        std::cin >> score1 >> score2 >> score3 >> score4;
        birth.day = day;
        birth.month = month;
        birth.year = year;
        p = createNode(id, name, birth, sex, score1, score2, score3, score4);
        r->next = p;
        r = p;
        std::cin >> id;
    }
    return head;
}

void outputNode(_STUDENT* p)        //输出链表，即输出所有的学生信息，传入值是表头地址
{
    int i = 0;                   //把p指针定位到链表的第一个非表头元素
    do
    {
        p = p->next;
        i++;
        std::cout << i << ".\t" << p->id << '\t' << p->name << '\t' << p->birth.year << '/' << p->birth.month << '/' << p->birth.day << '\t';
        std::cout << p->sex << '\t' << p->score1 << '\t' << p->score2 << '\t' << p->score3 << '\t' << p->score4 << std::endl;
    } while (p->next != NULL);
}

_STUDENT* searchNode(_STUDENT* p, std::string name)     //按照名字查找结点，传入值是表头地址和名字，暂时不支持重名查找
{
    do
    {
        p = p->next;
        if (p->name == name)
            return p;
    } while (p->next != NULL);
    return NULL;
}

_STUDENT* readFromFile()
{
    std::ifstream file1;
    std::string filename;
    std::cout << "Please input your information file path." << std::endl;
    std::cout << "Note that your file name should not include Chinese characters. " << std::endl;
    std::cout << "Also note that there should not be an enter at the end of the input file." << std::endl;
    std::cout << "Include student's ID, name, birth date, sex(0 is man, 1 is woman), score1, score2, score3, score4 like this:" << std::endl;
    std::cout << "000 dyy 1970/1/1 0 100 100 100 100" << std::endl << std::endl;
    std::cin >> filename;
    file1.open(filename, std::ios::in);
    int id;
    std::string name;
    _STUDENT::birthdate birth;
    unsigned year;
    unsigned month;
    unsigned day;
    sextype sex;
    bool sexn;
    int score1;
    int score2;
    int score3;
    int score4;
    char separate;
    //bool flag = false;
    _STUDENT* head = createHead();
    _STUDENT* p = head;
    _STUDENT* r = head;
    
    while (!file1.eof())
    {
        file1 >> id >> name >> year >> separate >> month >> separate >> day;
        file1 >> sexn;
        file1 >> score1 >> score2 >> score3 >> score4;
        if (sexn == 0)
            sex = man;
        else
            sex = woman;
        birth.day = day;
        birth.month = month;
        birth.year = year;
        p = createNode(id, name, birth, sex, score1, score2, score3, score4);
        r->next = p;
        r = p;
    }
    return head;
}

void writeToFile(_STUDENT* p)
{
    if(p->next == NULL)
    {
        std::cout << "It seems that you haven't entered any information." << std::endl;
        return;
    }
    std::ofstream file1;
    file1.open("student_info.txt", std::ios::out);
    do
    {
        p = p->next;
        file1 << p->id << '\t' << p->name << '\t' << p->birth.year << '/' << p->birth.month << '/' << p->birth.day << '\t';
        file1 << p->sex << '\t' << p->score1 << '\t' << p->score2 << '\t' << p->score3 << '\t' << p->score4 << '\n';
    } while (p->next != NULL);
    file1.close();
}

void addToNode(_STUDENT* p, int id, std::string name, _STUDENT::birthdate birth, sextype sex, int score1, int score2, int score3, int score4)
{
    _STUDENT* r = createNode(id, name, birth, sex, score1, score2, score3, score4);
    p->next = r;
}
