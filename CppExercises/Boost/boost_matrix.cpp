#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

int main () {
  // exploit namespaces to simplify code
  using namespace boost::numeric::ublas;
  using std::cout; using std::endl;

  // declare three 3x3 matrices of complex<long double> elements
  matrix<std::complex<long double> > m(3, 3), n(3, 3), o(3, 3);

  // iterate over 3x3 matrix entries
  for (unsigned i = 0; i < m.size1(); i++)
    for (unsigned j = 0; j < m.size2(); j++) {
      // enumerated matrix entries
      m(i,j) = 3 * i + j;

      // complex numbers designating rows and cols
      n(i,j) = i + j * 1i;

      // elementwise square of n
      o(i,j) = std::pow(n(i,j), 2);
    }

  // print to screen as demonstration
  cout << "m:" << endl;
  cout << m << endl;
  cout << endl << "n:" << endl;
  cout << n << endl;
  cout << endl << "o:" << endl;
  cout << n << endl;
  cout << endl << "m + n:" << endl;
  cout << m + n << endl;
  cout << endl << "m * n:" << endl;
  cout << prod(m, n) << endl;
  cout << endl << "n * n - o:" << endl;
  cout << prod(n, n) - o << endl;
}
