#include <iostream>
/**
 * pisano_len - Computing the period of a fibonacci number pattern
 * @m: The number used to compute the pisano period
 * Return: The length of the period or -1 on error
 */
long long pisano_len(long long m) {
        int i;
        long long numb1, numb2, len;

        numb1 = 0;
        numb2 = 1;
	len = numb1 + numb2;
        for (i = 1; i < (m * m); i++) {
                len = ((numb1 + numb2) % m);
                numb1 = numb2;
                numb2 = len;
		if (numb1 == 0 && numb2 == 1) {
			return (i);
		}
	}
	return (-1);
}
/**
 * fibHuge - Give the remainder of n modulus m
 * @n: The number to find the remainder of
 * @m: The divisor or number to divide into n
 * Return: The remainder
 */
long long fibHuge(long long n, long long m) {
	long long numb1, numb2, result, sum;
	int i;

	if (n <= 1) {
		return (n);
	}
	result = pisano_len(m);
	if (result == -1) {
		printf("Error!\n");
		exit(1);
	}
	result = n % result;
	if (result == 0) {
		return (result);
	}
	numb1 = 0;
	numb2 = 1;
	sum = numb1 + numb2;
	for (i = 1; i < result; i++) {
		sum = (numb1 + numb2) % m;
		numb1 = numb2;
		numb2 = sum;
	}
	return (sum);
}
/**
 * main - Find the modulus of a large number and return the remainder
 * Return: Always return 0
 */
int main(void) {
	long long result, n, m;

	std::cin >> n >> m;
	result = fibHuge(n, m);
	std::cout << result << '\n';
	return (0);
}
