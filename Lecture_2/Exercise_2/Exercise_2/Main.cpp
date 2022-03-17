#include <iostream>
#include <cstring>

// using namespace std;

class Student
{
    int ID;
    char* name;
    char group_series[6];
    int grades_sem1[5];

public:
    Student();
    ~Student();

    void init(int, const char*, char[], int[]);
    void display();
    void modify(const char[]);
    void modify(const int, const int);
    void copy(const Student&);

    float average();
    void sortArray(Student*, int);
};

Student::Student()
{
    ID = 0;
    name = NULL;
    for (int i = 0; i < 6; i++)
    {
        group_series[i] = '0';
    }
    for (int i = 0; i < 5; i++)
    {
        grades_sem1[i] = 0;
    }
}

Student::~Student()
{
    delete[] name;
}

void Student::init(int id, const char* n, char grp_s[], int grades[])
{
    ID = id;
    if (name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    strcpy(group_series, grp_s);
    for (int i = 0; i < 5; i++)
    {
        grades_sem1[i] = grades[i];
    }
}

void Student::display()
{
    std::cout << "ID: " << ID << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Group/Series: " << group_series << "\n";
    std::cout << "Grades (sem 1): ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << grades_sem1[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

void Student::modify(const char grp_s[])
{
    strcpy(group_series, grp_s);
}

void Student::modify(const int pos, const int grade)
{
    grades_sem1[pos] = grade;
}

void Student::copy(const Student& obj)
{
    ID = obj.ID;
    if (name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);
    strcpy(group_series, obj.group_series);
    for (int i = 0; i < 5; i++)
    {
        grades_sem1[i] = obj.grades_sem1[i];
    }
}

float Student::average()
{
    float S = 0;
    for (int i = 0; i < 5; i++)
    {
        S += grades_sem1[i];
    }

    return S / 5;
}

void Student::sortArray(Student* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i].average() > arr[j].average())
            {
                Student aux;
                aux.copy(arr[i]);
                arr[i].copy(arr[j]);
                arr[j].copy(aux);
            }
}

int main()
{
    int ID_1 = 1;
    const char* name_1 = "Student 1";
    char group_series_1[6] = "314AB";
    int grades_1[5] = { 9, 8, 10, 8, 9 };

    Student obj;
    obj.init(ID_1, name_1, group_series_1, grades_1);
    obj.display();
    obj.modify("321AB");
    obj.modify(3, 10);
    obj.display();

    int n;
    std::cout << "Enter dimension of array: ";
    std::cin >> n;
    std::cout << std::endl;

    Student* arr;
    arr = new Student[n];

    int ID;
    char* name;
    char group_series[6];
    int grades_sem1[5] = { 0 };
    for (int i = 0; i < n; i++)
    {
        std::cout << "STUDENT " << i + 1 << "\n";
        std::cout << "Enter ID: ";
        std::cin >> ID;
        std::cout << "Enter name: ";
        name = new char[20];
        std::cin >> name;
        std::cout << "Enter group/series: ";
        std::cin >> group_series;
        std::cout << "Enter grades:\n";
        for (int j = 0; j < 5; j++)
        {
            std::cout << "\tGrade " << j + 1 << ": ";
            std::cin >> grades_sem1[j];
        }
        std::cout << std::endl;
        arr[i].init(ID, name, group_series, grades_sem1);

        delete[] name;
    }
    arr->sortArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        arr[i].display();
    }

    delete[] arr;

    return 0;
}
