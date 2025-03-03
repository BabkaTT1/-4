#include <iostream>
int tran(int rows, int columns, int **mat, int** matrix, int c, int m) {
    for (int i{}; i < rows; i++)
    {
        c++;
        for (int j{}; j < columns; j++)
        {
            mat[j][i] = matrix[i][j];
            c++;
            m++;
        }
    }
    return mat, c, m;
}
//int Random(int columns, int rows, int** matrix)
//{
//    for (int i{}; i < rows; i++)
//    {
//        for (int j{}; j < columns; j++)
//        {
//            matrix[i][j] = rand() % 10;
//        }
//    }
//    return matrix;
//} ВЫДАЁТ ОШИБКУ "НЕВОЗМОЖНО ПРЕОБРАЗОВАТЬ int* В int!
 

int Output(int columns, int rows, int** mat)
{
    for (int i{}; i < columns; i++)
    {
        for (int j{}; j < rows; j++)
        {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
} /*ВЫДВЁТ ОШИБКУ */
unsigned int start_time = clock();
int main()
{
    clock_t start, end;
    setlocale(LC_ALL, "ru");
    int c = 0;
    int m = 0;
    int rows;
    int columns;
    std::cout << "Дайте количество строк и колонн, плиз\n";
    std:: cin >> rows >> columns;
    start = clock();
    int** matrix{ new int* [rows] {} };  // выделяем память под двухмерный массив
    for (int i{}; i < rows; i++)
    {
        matrix[i] = new int[columns] {};
    }
    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < columns; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
    Output(rows, columns, matrix);
   /* for (int i{}; i < rows; i++)
    {
        for (int j{}; j < columns; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }*/
    int** mat{ new int* [columns] {} };  // выделяем память под двухмерный массив
    for (int i{}; i < columns; i++)
    {
        mat[i] = new int[rows] {};
    }
    tran(rows, columns, mat, matrix, c, m);
    std::cout << "Трансформер найден:\n";
    Output(columns, rows, mat);
    //for (int i{}; i < columns; i++)
    //{
    //    for (int j{}; j < rows; j++)
    //    {
    //        std::cout << mat[i][j] << "\t";
    //    }
    //    std::cout << std::endl;
    //}
    std::cout << "Начинаем удаление матрицы\n";
    for (int i{}; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    std::cout << "Заканчиваем удаление матрицы1\n";
    for (int j{}; j < columns; j++)
    {
        delete[] mat[j];
    }
    delete[] mat; /*НЕ УВЕРЕН ЧТО ОН ТЕПЕРЬ УДАЛЯЕТ ЭТИ МАТРИЦЫ НО ПО--ДРУГОМУ НЕ РАБОТАЕТ*/
    std::cout << "Заканчиваем удаление матрицы2\n";
    std::cout << c << "\n" << m << "\n"; /*ВЫДАЁТ ОБА ЗНАЧЕНИЯ КАК НОЛЬ И ВСЁ*/
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Время: " << std::fixed
        << time_taken;
    std::cout << " секунд " << std::endl;
}

//    std::cout << "Штука для строки #" << (i + 1) << std::endl;
//    // вводим данные для столбцов i-й строки
//    for (int j{}; j < columns; j++)
//    {
//        std::cout << "Cтолбняк #" << (j + 1) << ": ";
//        std::cin >> matrix[i][j];
//    }
//}
//// вывод данных