#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <iterator>

class solution {
public:
    int rangeBitwiseAnd(int m, int n) {
	int result;
	if (m == 0)
	    result = 0;
	else {
	    int lb = 1, ub = 1;
	    while (int(pow(2,lb)) <= m)
		lb++;
	    lb = int(pow(2,lb-1));
	    while (int(pow(2,ub)) < n)
		ub++;
	    ub = int(pow(2,ub));
	    std::cout << "lb = " << lb << ", ub = " << ub << std::endl;
	    
	    if (ub != 2*lb)
		result = 0;
	    else {
		std::bitset<32> bset(m);
		int diff = n-lb;
		int nbits = 0;
		while (int(pow(2, nbits)) <= diff)
		    nbits++;
		std::cout << "Affected number of bits is: " << nbits << std::endl;
		for (size_t i = 0; i < nbits; i++)
		    bset[i] = 0;
		result = int(bset.to_ulong());
	    }
	}
	return result;
    }

    int bruteForce(int m, int n) {
	int count = m;
	std::vector<int> nums;
	std::generate_n(std::inserter(nums, nums.begin()), n-m+1, [&](){return count++;});
	// std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
	// std::cout << std::endl;
	return std::accumulate(nums.begin(), nums.end(), m, std::bit_and<int>());
    }
};

int main() {
    int m = 80, n = 87;

    solution soln;
    int rs = soln.rangeBitwiseAnd(m, n);
    std::cout << "The bitwise and result is:\n"
	      << rs << std::endl;
    std::cout << "The brute force result is:\n"
	      << soln.bruteForce(m, n) << std::endl;
}
