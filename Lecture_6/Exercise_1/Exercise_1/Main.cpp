#include "Class.h"

int main()
{
    std::cout << "This student:\n";
    int grades[] = { 9, 8 };
    char group[] = "314AC";
    Student X("Maximilian", grades, 2, "Decebal", group);
    std::cout << X << std::endl;

    std::cout << "Same student:\n";
    Student Y;
    Y = X;
    Y.modify("Romulus");
    std::cout << Y << std::endl;

    std::cout << "A non-existent student:\n";
    Student Unknown;
    std::cout << Unknown << std::endl;

    int n;
    std::cout << "Enter number of students (> 10): ";
    std::cin >> n;
    std::cout << std::endl;

    Student* S;
    S = new Student[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "STUDENT " << i + 1 << "\n";
        std::cin >> S[i];
    }

    std::cout << "Students sorted by average grade:\n";
    Class C(S, n);
    C.sortStudents();
    std::cout << C;

    std::cout << "After changing the professor:\n";
    const char* name = "Napoleon";
    C.modify(name);
    std::cout << C;

    Student new_S;
    std::cout << "Enter data about the new student:\n";
    std::cin >> new_S;

    std::cout << "After adding the new student:\n";
    S = C.addStudent(S, 2, new_S);
    if (S != NULL)
    {
        Class new_C(S, n + 1);
        C = new_C;
    }
    std::cout << C;
    C.addStudent(S, 100, new_S);

    delete[] S;

    return 0;
}
