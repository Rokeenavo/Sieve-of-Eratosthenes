
#include <iostream>
using namespace std;

int sieve_of_eratosthenes(int** primes, const int max) {
	int* isPrime = (int*)malloc(sizeof(int) * (max + 1));
	int i;
	for (i = 0; i <= max; ++i)
		isPrime[i] = 1;
	isPrime[0] = 0;
	isPrime[1] = 0;
	int count = 0;
	for (i = 2; i <= max; ++i)
	{
		if (isPrime[i] == 1)
		{
			++count;
			int j;
			for (j = 2 * i; j <= max; j += i)
				isPrime[j] = 0;
		}
	}
	*primes = (int*)malloc(sizeof(int) * count);
	int j = 0;
	for (i = 0; i <= max; ++i)
	{
		if (isPrime[i] == 1)
		{
			(*primes)[j++] = i;
		}
	}
	return count;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n, i;
	cout << "До какого числа найти простые числа?" << endl;
	cin >> n;
	int* primes = NULL;
	int size = sieve_of_eratosthenes(&primes, n);
	cout << "Простые числа до " << n << ":"<< endl;
	for (i = 0; i < size; ++i)
	{
		cout << primes[i] << " ";
	}
	return 0;
}