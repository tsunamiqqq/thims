#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

// Функція для обчислення факторіалу (потрібна для формули Пуассона)
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    return fact;
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    int n_clients = 100;
    double p = 0.01;
    double lambda = n_clients * p;
    
    cout << "Розподіл Пуассона\n";
    cout << "Середнє число дзвінків = " << lambda << "\n\n";
    cout << "Дзвінки\t\t Ймовірність\n";

    for (int k = 0; k <= 5; k++) {
        double prob = (pow(lambda, k) * exp(-lambda)) / factorial(k);
        cout << k << "\t\t " << fixed << setprecision(5) << prob << "\n";
    }

    return 0;
}
