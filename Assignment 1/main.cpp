#include <iostream>
#include <ctime>
#include <iomanip>

double optionA(int N) {
    //optionA
    float A[N][N];
    clock_t start1, stop1;
    start1 = clock();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 0.0;
        }
    }
    for (int i = 0; i < N; i++) {
        A[i][i] = 1.0;
    }
    stop1 = clock();
    return (double) (stop1 - start1);
}

double optionB(int N) {
    //optionB
    float B[N][N];
    clock_t start2, stop2;
    start2 = clock();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                B[i][j] = 1.0;
            } else {
                B[i][j] = 0.0;
            }
        }
    }
    stop2 = clock();
    return (double) (stop2 - start2);
}

int main() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Welcome to ECE3020 - Assignment 1" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Please enter the upper-bound size of the matrix you want to compute runtimes for: " << std::endl;
    int N;
    std::cin >> N;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Runtime option A" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    double avgRuntimeA, avgRuntimeB = 0;
    double totalRuntimeA, totalRuntimeB = 0;
    double numIterations = 50;
    for (int i = 0; i <= N; i = i + 50) {
        for (int j = 0; j < numIterations; j++) {
            totalRuntimeA += optionA(i);
        }
        avgRuntimeA = totalRuntimeA / numIterations;
        std::cout << i << "\t" << std::setprecision(10) << avgRuntimeA / CLOCKS_PER_SEC << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Runtime option B" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    for (int i = 0; i <= N; i = i + 50) {
        for (int j = 0; j < numIterations; j++) {
            totalRuntimeB += optionB(i);
        }
        avgRuntimeB = totalRuntimeB / numIterations;
        std::cout << i << "\t" << std::setprecision(10) << avgRuntimeB / CLOCKS_PER_SEC << std::endl;
    }
    return 0;
}
