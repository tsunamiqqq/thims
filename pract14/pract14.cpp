#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double get_t_laplace(double gamma) {
    if (gamma == 0.95) return 1.96;
    if (gamma == 0.99) return 2.576;
    if (gamma == 0.999) return 3.29;
    return 0.0;
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    double sigma = 3.0;
    double x_mean = 10.2;
    int n = 36;
    double gamma = 0.95;

    double t = get_t_laplace(gamma);
    
    if (t == 0.0) {
        cout << "Невідоме значення надійності\n";
        return 1;
    }

    double delta = t * (sigma / sqrt(n));

    double lower_bound = x_mean - delta;
    double upper_bound = x_mean + delta;

    cout << "Надійний інтервал для математичного сподівання\n";
    cout << "t = " << t << "\n";
    cout << "Точність = " << delta << "\n";
    cout << "Інтервал: " << lower_bound << ";" << upper_bound << "\n";

    return 0;
}
