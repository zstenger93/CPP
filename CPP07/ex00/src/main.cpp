#include "../includes/whatever.hpp"

class Awesome {
   public:
	Awesome(void) : _n(0) {}
	Awesome(int n) : _n(n) {}
	Awesome &operator=(Awesome &a) {
		_n = a._n;
		return *this;
	}
	bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
	bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
	bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
	bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
	bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
	bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
	int get_n() const { return _n; }

   private:
	int _n;
};
std::ostream &operator<<(std::ostream &o, const Awesome &a) {
	o << a.get_n();
	return o;
}

int main(void) {
	int a = 2;
	int b = 3;
	std::cout << "\033[1;4;31mBefore swap:\033[0;0;39m "
			  << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "Swappin..." << std::endl;
	std::cout << "\033[1;4;31mAfter swap:\033[0;0;39m "
			  << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "\033[1;4;31mBefore swap:\033[0;0;39m "
			  << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "Swappin..." << std::endl;
	std::cout << "\033[1;4;31mAfter swap:\033[0;0;39m "
			  << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;


	Awesome x(2), l(4);

	swap(x, l);
	std::cout << x << " " << l << std::endl;
	std::cout << max(x, l) << std::endl;
	std::cout << min(x, l) << std::endl;
	return 0;
}
