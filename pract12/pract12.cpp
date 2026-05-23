#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    vector<int> sample = {2, 6, 5, 6, 7, 6, 5, 6, 9, 2, 7, 6, 5, 6, 5, 7, 6, 2, 6, 5, 9, 7, 6, 5, 6};
    int n = sample.size();

    sort(sample.begin(), sample.end());
    
    cout << "Варіаційний ряд\n";
    for (int x : sample) {
        cout << x << " ";
    }
    cout << "\n\n";

    map<int, int> freqs;
    for (int x : sample) {
        freqs[x]++;
    }

    cout << "Статистичний розподіл вибірки\n";
    cout << "x_i\t| n_i\t| W_i\n";
    
    for (auto const& [val, count] : freqs) {
        double w_i = (double)count / n;
        cout << val << "\t| " << count << "\t| " << fixed << setprecision(2) << w_i << "\n";
    }
    cout << "\n";
    cout << "Сума\t  " << n << "\t  1.00\n\n";

    cout << "Координати точок для полігону\n";
    for (auto const& [val, count] : freqs) {
        double w_i = (double)count / n;
        cout << "(" << val << "; " << fixed << setprecision(2) << w_i << ")  ";
    }
    cout << "\n\n";

    cout << "Емпірична функція F*(x)\n";
    double current_f = 0.0;
    
    auto it = freqs.begin();
    cout << "0.00, при x <= " << it->first << "\n";
    
    for (auto prev = freqs.begin(); it != freqs.end(); ++it) {
        current_f += (double)it->second / n;
        auto next_it = it;
        ++next_it;
        
        if (next_it != freqs.end()) {
            cout << fixed << setprecision(2) << current_f 
                 << ", при " << it->first << " < x <= " << next_it->first << "\n";
        } else {
            cout << fixed << setprecision(2) << current_f 
                 << ", при x > " << it->first << "\n";
        }
    }

    return 0;
}
