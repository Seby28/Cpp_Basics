#include <iostream>
#include <cstring>

// using namespace std;

class Employee
{
    char* name;
    char* company;
    char CNP[14];
    int salary;

public:
    Employee();
    Employee(const char*, const char*, char[], int);
    ~Employee();

    void display();
    void modify(const char*, const char*, char[], int);
    void modify(const Employee&);

    char* getName() const;
    int getSalary() const;
    void readArray(Employee*, int);
    void sortArray(Employee*, int);
    void maxSalary(Employee*, int);
};

Employee::Employee()
{
    name = NULL;
    company = NULL;
    for (int i = 0; i < 14; i++)
    {
        CNP[i] = '0';
    }
    salary = 0;
}

Employee::Employee(const char* n, const char* c, char C[], int s)
{
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    company = new char[strlen(c) + 1];
    strcpy(company, c);
    strcpy(CNP, C);
    salary = s;
}

Employee::~Employee()
{
    delete[] name;
    delete[] company;
}

void Employee::display()
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Company: " << company << "\n";
    std::cout << "CNP: " << CNP << "\n";
    std::cout << "Salary = " << salary << "\n";
    std::cout << std::endl;
}

void Employee::modify(const char* n, const char* c, char C[], int s)
{
    if (name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    if (company != NULL)
    {
        delete[] company;
    }
    company = new char[strlen(c) + 1];
    strcpy(company, c);
    strcpy(CNP, C);
    salary = s;
}

void Employee::modify(const Employee& obj)
{
    if (name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);
    if (company != NULL)
    {
        delete[] company;
    }
    company = new char[strlen(obj.company) + 1];
    strcpy(company, obj.company);
    strcpy(CNP, obj.CNP);
    salary = obj.salary;
}

char* Employee::getName() const
{
    return name;
}

int Employee::getSalary() const
{
    return salary;
}

void Employee::readArray(Employee* arr, int n)
{
    char* aux_name;
    char* aux_company;
    char aux_CNP[14];
    int aux_salary;
    for (int i = 0; i < n; i++)
    {
        std::cout << "EMPLOYEE " << i + 1 << "\n";
        std::cout << "Enter name: ";
        aux_name = new char[20];
        std::cin >> aux_name;
        std::cout << "Enter company: ";
        aux_company = new char[20];
        std::cin >> aux_company;
        std::cout << "Enter CNP: ";
        std::cin >> aux_CNP;
        std::cout << "Enter salary: ";
        std::cin >> aux_salary;
        std::cout << std::endl;
        arr[i].modify(aux_name, aux_company, aux_CNP, aux_salary);

        delete[] aux_name;
        delete[] aux_company;
    }
}

void Employee::sortArray(Employee* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(arr[i].getName(), arr[j].getName()) > 0)
            {
                Employee aux;
                aux.modify(arr[i]);
                arr[i].modify(arr[j]);
                arr[j].modify(aux);
            }
}

void Employee::maxSalary(Employee* arr, int n)
{
    int max_salary = 0;
    for (int i = 0; i < n; i++)
        if (arr[i].getSalary() > max_salary)
        {
            max_salary = arr[i].getSalary();
        }
    std::cout << "Employees with the biggest salary:\n";
    for (int i = 0; i < n; i++)
        if (arr[i].getSalary() == max_salary)
        {
            std::cout << arr[i].getName() << "\n";
        }
}

int main()
{
    const char* name_1 = "Employee 1";
    const char* company_1 = "Company 1";
    char CNP_1[14] = "9876543456789";
    const char* name_2 = "Employee 2";
    const char* company_2 = "Company 2";
    char CNP_2[14] = "0123456543210";

    Employee obj(name_1, company_1, CNP_1, 2500);
    obj.display();
    obj.modify(name_2, company_2, CNP_2, 3500);
    obj.display();
    int x_salary = obj.getSalary();
    std::cout << "Salary = " << x_salary << "\n";
    char* x_name = obj.getName();
    std::cout << "Name: " << x_name << "\n\n";

    int n;
    std::cout << "Enter dimension of array: ";
    std::cin >> n;
    std::cout << std::endl;

    Employee* arr;
    arr = new Employee[n];

    arr->readArray(arr, n);
    arr->sortArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        arr[i].display();
    }
    arr->maxSalary(arr, n);

    delete[] arr;

    return 0;
}
