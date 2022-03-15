#include <iostream>
#include <iomanip>

// using namespace std;

int** allocate_matrix(int, int);

void free_matrix(int**, int, int);

void read_matrix(int**, int, int, char);

void print_matrix(int**, int, int);

int** square_matrix(int**, int, int);

int diag1_sum(int**, int, int);

int main()
{
    int** m, l, c;
    std::cout << "Enter number of rows: ";
    std::cin >> l;
    std::cout << "Enter number of columns: ";
    std::cin >> c;

    m = allocate_matrix(l, c);
    read_matrix(m, l, c, 'M');
    print_matrix(m, l, c);

    std::cout << "\nSum of diagonal elements of matrix: " << diag1_sum(m, l, c) << std::endl;

    int** square_m = square_matrix(m, l, c);
    if (square_m != NULL)
    {
        print_matrix(square_m, l, c);
    }

    free_matrix(square_m, l, c);
    free_matrix(m, l, c);

    return 0;
}

int** allocate_matrix(int l, int c)
{
    int** m;
    m = new int* [l];
    for (int i = 0; i < l; i++)
    {
        m[i] = new int[c];
    }

    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
        {
            m[i][j] = 0;
        }

    return m;
}

void free_matrix(int** m, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        delete[] m[i];
    }
    delete[] m;
}

void read_matrix(int** m, int l, int c, char name)
{
    for (int i = 0; i < l; i++)
        for (int j = i; j < c; j++)
        {
            std::cout << 'M' << "[" << i << "][" << j << "] = ";
            std::cin >> m[i][j];
        }
}

void print_matrix(int** m, int l, int c)
{
    std::cout << "\nMatrix: " << std::endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << std::setw(3) << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int** square_matrix(int** m, int l, int c)
{
    int** res;
    if (l != c)
    {
        std::cout << "Cannot square matrix." << std::endl;
        return 0;
    }
    else
    {
        res = allocate_matrix(l, c);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++)
                for (int k = 0; k < l; k++)
                {
                    res[i][j] += m[i][k] * m[k][j];
                }
    }

    return res;
}

int diag1_sum(int** m, int l, int c)
{
    int S = 0;
    if (l == c)
        for (int i = 0; i < l; i++)
        {
            S += m[i][i];
        }
    else
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
                if (i == j)
                {
                    S += m[i][j];
                }

    return S;
}
