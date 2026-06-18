#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point
{
  double x;
  double p;
};

int main()
{
  std::vector<Point> data = {{-2, 0.2}, {1, 0.28}, {3, 0.42}, {5, 0.1}};

  double mX = 0;
  double mX2 = 0;

  for (const auto &item : data)
  {
    mX += item.x * item.p;
    mX2 += (item.x * item.x) * item.p;
  }

  double dX = mX2 - (mX * mX);
  double sigma = std::sqrt(dX);

  std::cout << std::fixed << std::setprecision(4);
  std::cout << "Математичне сподівання: " << mX << std::endl;
  std::cout << "Дисперсія: " << dX << std::endl;
  std::cout << "Середнє квадратичне відхилення: " << sigma << std::endl;

  return 0;
}
