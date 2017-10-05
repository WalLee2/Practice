#include <iostream>
#include <vector>
#include <cstdlib>
/**
 * get_optimal_value - Returns the largest value produced from computing an
 * item's value relative to their weight. This algorithm is slower.
 * @capacity: The maximum amount of weight
 * @weights: A vector that holds the weight of each item
 * @values: A vector that holds the value of each item
 * Return: The largest sum of all items that does not exceed capacity.
 */
using std::vector;
using std::cout;

double get_optimal_value(int capacity, vector<double> weights, vector<double> values) {
	double value = 0.0;
	double ratio, max_ratio, w, flag, weight;
	unsigned int i, index, j;

	w = max_ratio = flag = weight = ratio = 0;
	index = 0;
	if (weights.size() == 1 && weights[0] < capacity) {
		return (values[0]);
	}
	while (w < capacity) {
		for (i = 0; i < weights.size(); ++i) {
			if (weights[i] <= capacity && weights[i] != 0) {
				ratio = values[i] / weights[i];
			} else if (weights[i] > capacity && weights[i] != 0) {
				values[i] = (values[i] * capacity) / weights[i];
				ratio = values[i] / weights[i];
				weights[i] -= (weights[i] - capacity);
			}
			if (ratio > max_ratio) {
				max_ratio = ratio;
				index = i;
				weight = weights[i];
			} else if (ratio == max_ratio && weights[i] < weight) {
				index = i;
				weight = weights[i];
			}
		}
		if (max_ratio && (w + weights[index]) <= capacity) {
			value += values[index];
			w += weights[index];
			values.erase(values.begin() + index);
			weights.erase(weights.begin() + index);
			max_ratio = 0;
		}
	}
	return (value);
}
/**
 * main - Takes in user input. In the first line, the first number entered
 * represents the number of items the knapsack can hold. The second number
 * enetered represents the maximum capacity of the knapsack. Subsequent lines
 * entered by the user represents the value and weight of the item respectively
 * Return: Function always returns 0
 */
int main(void) {
	int n;
	int capacity;

	std::cin >> n >> capacity;
	vector<double> values(n);
	vector<double> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}
	std::cout.precision(10);
	double optimal_value = get_optimal_value(capacity, weights, values);
	std::cout << optimal_value << std::endl;
	return (0);
}
