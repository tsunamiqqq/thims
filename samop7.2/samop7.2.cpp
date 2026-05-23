#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    double p = 0.9;
    double q = 0.1;
    
    cout << "Геометричний розподіл\n";
    cout << "Ймовірність правильної відповіді = " << p << "\n";
    cout << "Ймовірність помилки = " << q << "\n\n";
    cout << "Питання\t\t Ймовірність\n";

    for (int k = 1; k <= 5; k++) {
        double prob = pow(p, k - 1) * q;
        cout << k << "\t\t " << fixed << setprecision(5) << prob << "\n";
    }

    return 0;
}
