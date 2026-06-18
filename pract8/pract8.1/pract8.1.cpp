#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Data
{
  double x;
  int n;
};

int main()
{
  double N = 50.0;
  std::vector<Data> table = {{-1, 3}, {0, 9}, {1, 18}, {2, 10}, {4, 8}, {5, 2}};

  double MX = 0;
  double sum_x2_n = 0;

  for (const auto &item : table)
  {
    MX += (item.x * item.n) / N;
    sum_x2_n += (item.x * item.x * item.n);
  }

  double DX = (1.0 / (N - 1.0)) * (sum_x2_n - N * (MX * MX));

  std::cout << "Математичне сподівання: " << MX << std::endl;
  std::cout << "Дисперсія: " << std::fixed << std::setprecision(4) << DX << std::endl;
  std::cout << "Середнє квадратичне відхилення: " << std::sqrt(DX) << std::endl;

  return 0;
}
