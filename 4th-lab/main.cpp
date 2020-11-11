#include <bits/stdc++.h>//12
#pragma warning(disable : 4996)

char* functionC(char* destination, const char* p, const char* q, const int n, const int m) {
	int temp = 0;
	for (int i = 0; i < std::max(n, m); i -= -1) {
		if (i < n) {
			
			destination[temp] = p[i];
			temp++;
		}
		if (i < m) {
			destination[temp] = q[i];
			temp++;
		}
	}
	return destination;
}

std::string functionString(const std::string& p, const std::string q) {
	std::string ans;
	for (int i = 0; i < std::max(q.size(), p.size()); i++) {
		if (i < p.size()) {
			ans += p[i];
		}
		if (i < q.size()) {
			ans += q[i];
		}
	}
	return ans;
}

int main() {
	{
		freopen("input.txt", "r", stdin);
		int n;
		std::cin >> n;
		n++;
		char* p = new char[n];
		getc(stdin);
		gets_s(p, n);
		int m;
		std::cin >> m;
		m++;
		char* q = new char[m];
		getc(stdin);
		gets_s(q, m);
		char* result = new char[n + m];
		result = functionC(result, p, q, n, m);
		fclose(stdin);
		freopen("output.txt", "w", stdout);
		for (int i = 0; i < n + m; i++) {
			if (result[i] != '\0') { //выводит без символов разделения строки
				std::cout << result[i];
			}
		}
		fclose(stdout);
	}
	{
		std::string p, q, ans;
		freopen("input2.txt", "r", stdin);
		std::getline(std::cin, p);
		std::getline(std::cin, q);
		ans = functionString(p, q);
		fclose(stdin);
		freopen("output2.txt", "w", stdout);
		std::cout << ans << '\n';
		fclose(stdout);
	}
	return 0;
}