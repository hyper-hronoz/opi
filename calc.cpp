#include <iostream>
#include <cmath>

using namespace std;

double log2(double n) {
  return log(n) / log(2); 
};

int main() {
  double n1 = 42;
  double n2 = 20;

  double N1 = 364;
  double N2 = 161;

  double n = 62;

  double Ne = N1 + N2;
  cout << "Эксперементальная длина программы: " << Ne << endl;

  double N = n1 * log2(n1) + n1 * log2(n2);
  cout << "Теоретическая длина программы: " << N << endl;

  double V = N * log2(n);
  cout << "Объем программы: " << V << endl;

  double Vs = (2 + n2) * log2(2 + n2);
  cout << "Потенциальный (минимальный) объем: " << Vs << endl;

  double Vi = ((2 + n2) * log2(n2)) * log2(2 + n2);
  cout << "Граничный объем: " << Vi << endl;

  double A = n2 / (n2 + 2) * log2(n2 / 2);

  double L = Vs / V;
  cout << "Уровень программы: " << L << endl;

  double S = 1 / L;
  cout << "Сложность программы: " << S << endl;

  double Lc = 2 * n2 / (n1 * N2);
  cout << "Уровень качества программирования: " << Lc << endl;

  double I = Lc * V;
  cout << "Интеллектуальное содержаниe: " << I << endl;

  double E = V / L;
  cout << "Трудоемкость кодирования: " << E << " или " << V / L << endl;

  double T = E/18;
  cout << "Приближенное время программирования: " << T << endl;

  double Tc = ( n1 * N2 * (n1 * log(n1) / log(2) + n2*log(n2)/log(2)*n2) * log(n) / log(2)) / (2 * n2 * S);
  
  double la = pow(L, 2) * V;
  cout << "Уровень языка: " << T << endl;

  double E0 = (Vi * Vi * Vi) / (A * A);
  double B = V / E0;
  cout << "Уравнение ошибок: " << B << " или " << pow(E, 2/3) / 3000 << endl;

  double La = L * Vs;
  cout << "Уровень языка: " << La << endl;

  return 0;
}
