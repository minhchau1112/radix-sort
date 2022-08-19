#include<iostream>
#include<cmath>
using namespace std;


void RadixSort(int* a, int n) {
	if (n <= 0)return;
	int* b = new int[n];
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)max = a[i];
	}
	int x = 1;
	int d=0,index=0;
	while (max / x > 0) {
		int digit[10] = { 0 };
		for (int i = 0; i < n; i++) {
			d = (a[i] / x) % 10;
			digit[d]++;
		}
		for (int j = 1; j < 10; j++) {
			digit[j] += digit[j - 1];
		}
		for (int z = n - 1; z >= 0; z--) {
			d = (a[z] / x) % 10;
			digit[d]--;
			b[digit[d]] = a[z];
		}
		for (int k = 0; k < n; k++) {
			a[k] = b[k];
		}
		x *= 10;
	}
	delete[] b;
}
int main() {
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	RadixSort(a, n);
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	delete[] a;
	return 0;
}