/*я не знаю правильно я сделал или нет но решил сделать 
матрицу размером 10000x10000 и заполнить его случайными значениями.*/


#include <iostream>
#include <vector>
#include <chrono>

const int N = 10000;

//функция для суммирования элементов матрицы построчно (вдоль)
void sum_along_rows(const std::vector<std::vector<int>>& matrix) {
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sum += matrix[i][j];
        }
    }
    std::cout << "Sum along rows: " << sum << std::endl;
}

//функция для суммирования элементов матрицы по столбцам (поперек)
void sum_along_columns(const std::vector<std::vector<int>>& matrix) {
    long long sum = 0;
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            sum += matrix[i][j];
        }
    }
    std::cout << "Sum along columns: " << sum << std::endl;
}

int main() {
    //создаем матрицу
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 1000;
        }
    }
    
    auto start = std::chrono::high_resolution_clock::now();

    //измеряем время выполнения суммирования построчно
    sum_along_rows(matrix);
   
    
    //измеряем время выполнения суммирования по столбцам
    sum_along_columns(matrix);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken" << duration.count() << " seconds" << std::endl;
    
    matrix.clear();

    return 0;
}

/*

// valgrind --tool=cachegrind ./prof

Sum along rows: 49951420405
Sum along columns: 49951420405
Time taken: 85.0132 seconds

I   refs:      50,332,116,650
I1  misses:             2,741
LLi misses:             2,648
I1  miss rate:           0.00%
LLi miss rate:           0.00%

D   refs:      29,225,974,109  (19,616,885,318 rd   + 9,609,088,791 wr)
D1  misses:       163,406,098  (   150,837,561 rd   +    12,568,537 wr)
LLd misses:        56,928,477  (    44,411,925 rd   +    12,516,552 wr)
D1  miss rate:            0.6% (           0.8%     +           0.1%  )
LLd miss rate:            0.2% (           0.2%     +           0.1%  )

LL refs:          163,408,839  (   150,840,302 rd   +    12,568,537 wr)
LL misses:         56,931,125  (    44,414,573 rd   +    12,516,552 wr)
LL miss rate:             0.1% (           0.1%     +           0.1%  )
*/
