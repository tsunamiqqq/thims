#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {4.9, 5.9, 4.4, 3.4, 2.9};
    int n = x.size();

    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    double mean_x = sum_x / n;
    double mean_y = sum_y / n;
    double mean_x2 = sum_x2 / n;
    double mean_xy = sum_xy / n;

    double a = (mean_xy - mean_x * mean_y) / (mean_x2 - mean_x * mean_x);
    double b = mean_y - a * mean_x;

    cout << "Результати розрахунків прямої регресії\n";
    cout << fixed << setprecision(2);
    cout << "Середнє x: " << mean_x << "\n";
    cout << "Середнє y: " << mean_y << "\n\n";
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n\n";
    
    cout << "Рівняння прямої регресії: y = " << a << "x + " << b << "\n";

    return 0;
}
