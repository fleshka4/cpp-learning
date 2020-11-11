#include <iostream>

int validate() {
	int n;
	while (!(std::cin >> n))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');

		std::cout << "Error! Enter the number: ";
	}
	return n;
}

int main() {
	int n = validate(); 
	int temp = n;
	int count = 0;
	if (n != 0) {
		while (true) {
			n = validate();
			if (n == 0) {
				break;
			}
			if (n % temp == 0) {
				count++;
			}
			temp = n;
		}
	}
	std::cout << count << " element(s) of this sequence are divided by the preceding element without remainder";
	return 0;
}