#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
/**
 * maximize_revenue - Function that finds the largest value in profit per click
 * value and multiplies it with the largest click per day value to find where to
 * place ads for maximum value.
 * @ppclick: Vector that contains profit per click values
 * @cpday: Vector that contains clicks per day values
 * Return: The sum of all the (ppc * cpd) values
 */
long long maximize_revenue(vector<long long> ppclick, vector<long long> cpday) {
	int index1, index2;
	unsigned int i, j;
	long long total, bigclick, clickrate;

	total = 0;
	while (ppclick.size() && cpday.size()) {
		bigclick = -1000000;
		for (i = 0; i < ppclick.size(); ++i) {
			if (ppclick[i] >= bigclick) {
				bigclick = ppclick[i];
				index1 = i;
			}
		}
		clickrate = -1000000;
		for (j = 0; j < cpday.size(); ++j) {
			if (cpday[j] >= clickrate) {
				clickrate = cpday[j];
				index2 = j;
			}
		}
		total += (bigclick * clickrate);
		ppclick.erase(ppclick.begin() + index1);
		cpday.erase(cpday.begin() + index2);
		index1 = 0;
		index2 = 0;
	}
	return (total);
}
/**
 * main - The main function takes in user input. The first value is the number
 * is the number of ads to place on a popular internet page.
 * The second row represents the profit per click of the ad.
 * The Third row represents the clicks per day of the ad.
 * Return: Always returns 0.
 */
int main(void) {
	size_t n, i;

	cin >> n;
	vector<long long> profit_per_click(n);
	vector<long long> clicks_per_day(n);
	for (i = 0; i < n; ++i) {
		cin >> profit_per_click[i];
	}
	for (i = 0; i < n; ++i) {
		cin >> clicks_per_day[i];
	}
	cout << maximize_revenue(profit_per_click, clicks_per_day) << std::endl;
	return (0);
}
