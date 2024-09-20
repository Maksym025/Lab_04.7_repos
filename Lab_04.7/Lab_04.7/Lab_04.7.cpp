#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;

   
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "   |"
        << setw(10) << "arccot(x)" << " |"
        << setw(7) << "S" << "    |"
        << setw(5) << "n" << " |" << endl;
    cout << "-----------------------------------------" << endl;

    x = xp;

   
    while (x <= xk)
    {
      
        if (fabs(x) > 1) 
        {
            cout << "Error: x must be [-1, 1]" << endl;
            break;
        }
        else
        n = 0;   
        a = x;  
        S = a;
        double PI = 3.14;
        do {
          
          
            R = -x * x * (2 * n - 1) / (2 * n + 1); 
            a *= R;                              
            S += a;  
            n++;
        } while (fabs(a) >= eps);  

       
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << (PI / 2 - S) << " |"  
            << setw(10) << setprecision(5) << S << " |"
            << setw(5) << n << " |" << endl;

        x += dx; 
    }

    cout << "-----------------------------------------" << endl;
    return 0;
}