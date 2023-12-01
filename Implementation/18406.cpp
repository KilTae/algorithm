#include <iostream>
#include <string>
using namespace std;

int main() {
	string scores;
	cin >> scores;
	int sum1 = 0;
	int sum2 = 0;
	if (scores.size() % 2 == 0) {
		for (int i = 0; i < scores.size() /2; i++) {
			sum1 += scores[i];
		}
		for (int i = scores.size() / 2; i < scores.size(); i++) {
			sum2 += scores[i];
		}
		if (sum1 == sum2)
			std::cout << "LUCKY\n";
		else
			std::cout << "READY\n";
	}
	else std::cout << "FAIL\n";
	
}