#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    vector<int> a = {2, 6, 10, 14, 18, 22, 26};
    vector<int> n_i = {10, 16, 32, 24, 12, 6};

    int h = a[1] - a[0];
    int n = 0;
    
    for (int count : n_i) {
        n += count;
    }

    cout << "Ширина інтервалу h = " << h << "\n";
    cout << "Об'єм вибірки n = " << n << "\n\n";
    
    cout << left << setw(15) << "Інтервал\n" 
         << setw(10) << "n_i" 
         << setw(10) << "W_i" 
         << "\tВисота\n";
    cout << "--------------------------------------------------\n";

    for (size_t i = 0; i < n_i.size(); i++) {
        double w_i = (double)n_i[i] / n;
        double f_i = w_i / h;

        cout << a[i] << " - " << left << setw(11) << a[i+1] 
             << setw(10) << n_i[i] 
             << fixed << setprecision(2) << setw(10) << w_i 
             << fixed << setprecision(3) << f_i << "\n";
    }

    return 0;
}
