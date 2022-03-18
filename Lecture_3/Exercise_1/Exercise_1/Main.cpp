#include "Class.h"

int main()
{
    const char* name_1 = "Student 1";
    const char* faculty_1 = "ACS";
    char CNP_1[14] = "9876543456789";
    const char* name_2 = "Student 2";
    const char* faculty_2 = "ETTI";
    char CNP_2[14] = "0123456543210";

    Student obj(name_1, faculty_1, CNP_1, 2000);
    obj.display();
    obj.modify(name_2, faculty_2, CNP_2, 1998);
    obj.display();
    char* X_faculty = obj.getFaculty();
    std::cout << "Faculty: " << X_faculty << "\n";
    int X_year = getYear(obj);
    std::cout << "Age = " << X_year << "\n\n";

    int n;
    std::cout << "Enter dimension of array: ";
    std::cin >> n;
    std::cout << std::endl;

    Student* arr;
    arr = new Student[n];

    char* name;
    char* faculty;
    char CNP[14];
    int birth_year;
    for (int i = 0; i < n; i++)
    {
        std::cout << "STUDENT " << i + 1 << "\n";
        std::cout << "Enter name: ";
        name = new char[20];
        std::cin >> name;
        std::cout << "Enter faculty: ";
        faculty = new char[20];
        std::cin >> faculty;
        std::cout << "Enter CNP: ";
        std::cin >> CNP;
        std::cout << "Enter year of birth: ";
        std::cin >> birth_year;
        std::cout << std::endl;
        arr[i].modify(name, faculty, CNP, birth_year);

        delete[] name;
        delete[] faculty;
    }
    arr->sortArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        arr[i].display();
    }
    arr->printArray(arr, n);

    delete[] arr;

    return 0;
}
