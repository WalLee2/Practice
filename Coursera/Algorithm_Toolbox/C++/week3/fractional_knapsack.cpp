#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cout;
/**
 * find_max_index - Find the index that has the largest value to weight ratio
 * @weights: A vector that holds the weights of each item.
 * @values: A vector that holds the values of each item.
 * Return: The index that has the highest value to weight ratio.
 */
int find_max_index (vector<double> weights, vector<double> values) {
	int index;
	unsigned int i;
	double ratio;

	ratio = index = 0;
	for (i = 0; i < weights.size(); ++i) {
		if (weights[i] != 0 && (values[i] / weights[i]) > ratio) {
			ratio = values[i] / weights[i];
			index = i;
		}
	}
	return (index);
}
/**
 * get_optimal_value - Returns the largest value produced from computing an
 * item's value relative to their weight. This algorithm is faster.
 * @capacity: The maximum amount of weight
 * @weights: A vector that holds the weight of each item
 * @values: A vector that holds the value of each item
 * Return: The largest sum of all items that does not exceed capacity.
 */
double get_optimal_value(int capacity, vector<double> weights, vector<double> values) {
	double value = 0.0;
	double min_weight;
	int max_idx;
	unsigned int i;

	max_idx = min_weight = 0;
	for (i = 0; i < weights.size() && capacity != 0; ++i) {
		max_idx = find_max_index(weights, values);
		min_weight = std::min((int)weights[max_idx], capacity);
		value += min_weight * (values[max_idx] / weights[max_idx]);
		weights[max_idx] -= min_weight;
		capacity -= min_weight;
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
