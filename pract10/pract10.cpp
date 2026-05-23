#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    vector<double> X = {1, 4, 7, 10};
    vector<double> Y = {-2, 3, 8, 13};
    
    vector<vector<double>> P = {
        {0.02, 0.04, 0.03, 0.01},
        {0.06, 0.20, 0.10, 0.03},
        {0.06, 0.13, 0.11, 0.04},
        {0.03, 0.06, 0.06, 0.02}
    };

    int n = X.size();
    int m = Y.size();

    cout << fixed << setprecision(4);

    vector<double> PX(n, 0.0);
    vector<double> PY(m, 0.0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            PX[i] += P[i][j];
            PY[j] += P[i][j];
        }
    }

    cout << "Закони розподілу, компонент X та Y\n";
    cout << "P(X): ";
    for (int i = 0; i < n; i++) cout << PX[i] << "  ";
    cout << "\nP(Y): ";
    for (int j = 0; j < m; j++) cout << PY[j] << "  ";
    cout << "\n\n";

    double MX = 0, MX2 = 0, MY = 0, MY2 = 0, MXY = 0;

    for (int i = 0; i < n; i++) {
        MX += X[i] * PX[i];
        MX2 += X[i] * X[i] * PX[i];
        for (int j = 0; j < m; j++) {
            MXY += X[i] * Y[j] * P[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        MY += Y[j] * PY[j];
        MY2 += Y[j] * Y[j] * PY[j];
    }

    double DX = MX2 - MX * MX;
    double DY = MY2 - MY * MY;
    double sigmaX = sqrt(DX);
    double sigmaY = sqrt(DY);
    double cov = MXY - MX * MY;
    double r = cov / (sigmaX * sigmaY);

    cout << "Математичні сподівання\n";
    cout << "M(X) = " << MX << "\n";
    cout << "D(X) = " << DX << "; sigma = " << sigmaX << "\n";
    cout << "M(Y) = " << MY << "\n";
    cout << "D(Y) = " << DY << "; sigma = " << sigmaY << "\n";
    cout << "M(XY) = " << MXY << "\n";
    cout << "Cov(X,Y) = " << cov << "\n";
    cout << "r_xy = " << r << "\n\n";

    int a_idx = 1;
    int b_idx = 1;

    cout << "Умовні розподіли\n";
    
    cout << "Розподіл X при Y = 3:\n";
    double M_X_cond_Y = 0;
    for (int i = 0; i < n; i++) {
        double p_cond = P[i][a_idx] / PY[a_idx];
        M_X_cond_Y += X[i] * p_cond;
        cout << "P(X=" << X[i] << " | Y=3) = " << p_cond << "\n";
    }
    cout << "M(X|Y=3) = " << M_X_cond_Y << "\n\n";

    cout << "Розподіл Y при X = 4:\n";
    double M_Y_cond_X = 0;
    for (int j = 0; j < m; j++) {
        double p_cond = P[b_idx][j] / PX[b_idx];
        M_Y_cond_X += Y[j] * p_cond;
        cout << "P(Y=" << Y[j] << " | X=4) = " << p_cond << "\n";
    }
    cout << "M(Y|X=4) = " << M_Y_cond_X << "\n";

    return 0;
}
