#include <iostream>
#include <vector>
#include <cmath>

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
  for (auto const &item : table)
    MX += (item.x * item.n) / N;

  double MX2 = 0;
  for (auto const &item : table)
    MX2 += (item.x * item.x * item.n) / N;

  double DX = MX2 - (MX * MX);

  std::cout << "Математичне сподівання: " << MX << std::endl;
  std::cout << "Дисперсія: " << DX << std::endl;
  std::cout << "Середнє квадратичне відхилення: " << std::sqrt(DX) << std::endl;

  return 0;
}
