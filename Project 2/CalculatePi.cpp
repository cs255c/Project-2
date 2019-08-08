/* Calculate requested number of digits of pi
*  Alex Debrecht */

#include <iostream>
#include <cmath>
using namespace std;

// function main begins program execution
int main() {

	// Ask user for significant digits
	cout << "Enter the number of significant digits you would like." << endl;

	// Declare and initialize variables
	int sigFig;
	double piApprox = 0;
	double prevPiApprox;
	double denom = 1;
	long long loop = 0;
	double delta;
	int sign = 1;

	cin >> sigFig; // Accept number of significant figures from user

	delta = 1.0/pow(10,sigFig); // Calculate desired difference

	// Loop until condition inside is met
	do {

		prevPiApprox = piApprox; // set comparison
		loop = loop + 1;

		// Determine sign of fraction (positive for odd loop, negative for even loop)
		piApprox = piApprox + 4/denom*sign;
		denom = denom + 2;
		sign = -sign;

		// Print first 10 terms
		if (loop <= 10 && loop > 0) {
			cout << "π (pi) approximation #" << loop << ": " << piApprox << endl;
		}

	} while ((abs(prevPiApprox - piApprox)) > delta); // Test if difference is smaller than delta

	// Print final approximation and number of terms required
	cout.precision(sigFig);
	cout << "π (pi) ≈ " << piApprox << endl << "This approximation required " <<
			loop << " terms." << endl;

} // ends function main
