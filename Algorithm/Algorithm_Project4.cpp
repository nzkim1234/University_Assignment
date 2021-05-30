#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &vec) {
	int temp;
	for (int i = 0; i < vec.size()-1; i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[i] > vec[j]) {
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
}


int main() {
	int T_case;
	int t_case;
	int num;
	int sum;
	int total_sum;
	cin >> T_case;
	for (int i = 0; i < T_case; i++) {
		cin >> t_case;
		vector<int> vec;
		for (int j = 0; j < t_case; j++) {
			cin >> num;
			vec.push_back(num);
		}
		total_sum = 0;
		while (1) {
			sort(vec);
			sum = vec[0] + vec[1];
			vec.erase(vec.begin());
			vec.erase(vec.begin());
			vec.push_back(sum);
			if (vec.size() < 2)
				break;
			total_sum += sum;
		}
		total_sum += vec[0];
		cout << total_sum << endl;
	}
}