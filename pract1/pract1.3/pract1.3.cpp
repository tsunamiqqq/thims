#include <iostream>
#include <cmath>

int main()
{
  int chairs = 6;
  int materials = 12;

  long long ways = 1;
  for (int i = 0; i < chairs; ++i)
  {
    ways *= materials;
  }

  std::cout << "Способів: " << ways << std::endl;
  return 0;
}
