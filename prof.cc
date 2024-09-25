

#include <iostream>
#include <vector>
#include <chrono>

const int N = 10000;

// Функция для суммирования элементов матрицы построчно (вдоль)
void sum_along_rows(const std::vector<std::vector<int>>& matrix) {
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sum += matrix[i][j];  // Суммируем элементы строки
        }
    }
    std::cout << "Sum along rows: " << sum << std::endl;
}

// Функция для суммирования элементов матрицы по столбцам (поперек)
void sum_along_columns(const std::vector<std::vector<int>>& matrix) {
    long long sum = 0;
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            sum += matrix[i][j];  // Суммируем элементы столбца
        }
    }
    std::cout << "Sum along columns: " << sum << std::endl;
}

int main() {
    // Создаем двумерный массив (матрицу) и заполняем его случайными значениями
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 1000;  // Заполняем случайными числами
        }
    }
    
    auto start = std::chrono::high_resolution_clock::now();

    // Измеряем время выполнения суммирования построчно
    sum_along_rows(matrix);

// valgrind --tool=cachegrind ./prof

/* 
Sum along rows: 49948791381
Time taken 49.2709 seconds

I   refs:      36,032,772,434
I1  misses:             2,640
LLi misses:             2,530
I1  miss rate:           0.00%
LLi miss rate:           0.00%

D   refs:      20,526,402,255  (13,717,124,985 rd   + 6,809,277,270 wr)
D1  misses:        25,913,721  (    13,342,792 rd   +    12,570,929 wr)
LLd misses:        18,820,352  (     6,303,816 rd   +    12,516,536 wr)
D1  miss rate:            0.1% (           0.1%     +           0.2%  )
LLd miss rate:            0.1% (           0.0%     +           0.2%  )

LL refs:           25,916,361  (    13,345,432 rd   +    12,570,929 wr)
LL misses:         18,822,882  (     6,306,346 rd   +    12,516,536 wr)
LL miss rate:             0.0% (           0.0%     +           0.2%  )
*/   
    
    // Измеряем время выполнения суммирования по столбцам
    sum_along_columns(matrix);
/*
Sum along columns: 49947098384
Time taken56.7998 seconds

I   refs:      36,032,788,691
I1  misses:             2,643
LLi misses:             2,533
I1  miss rate:           0.00%
LLi miss rate:           0.00%

D   refs:      20,526,407,506  (13,717,130,216 rd   + 6,809,277,290 wr)
D1  misses:       157,160,238  (   144,589,309 rd   +    12,570,929 wr)
LLd misses:        50,664,501  (    38,147,965 rd   +    12,516,536 wr)
D1  miss rate:            0.8% (           1.1%     +           0.2%  )
LLd miss rate:            0.2% (           0.3%     +           0.2%  )

LL refs:          157,162,881  (   144,591,952 rd   +    12,570,929 wr)
LL misses:         50,667,034  (    38,150,498 rd   +    12,516,536 wr)
LL miss rate:             0.1% (           0.1%     +           0.2%  )
*/
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken" << duration.count() << " seconds" << std::endl;
    
    matrix.clear();

    return 0;
}

/*

все вместе

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
