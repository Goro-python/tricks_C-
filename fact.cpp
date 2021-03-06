#include <iostream>
#include <cassert>

using namespace std;





long long  fibonacci_fast(long long n) {
	// write your code here
	long long first = 0;
	long long second = 1;
	long long sum = 1;
	long long temp = 0;
	for (int i = 2; i < n; i++)
	{
		temp = second;
		second = sum;
		first = temp;
		sum = first + second;
	}
	if (n == 0)
		return first;
	if (n == 1)
		return second;

	return sum;
}


long long  fibonacci_fast_mod_m(long long n,long long m) {
	// write your code here
	long long first = 0;
	long long second = 1;
	long long sum = 1;
	long long temp = 0;
	for (int i = 2; i < n; i++)
	{
		temp = second;
		second = sum%m;
		first = temp%m;
		sum = (first + second)%m;
	}
	if (n == 0)
		return first;
	if (n == 1)
		return second;

	return sum%m;
}



int get_fibonacci_last_digit_fast(long long n) {

	int first = 0;
	int second = 1;
	int sum = 1;
	int temp = 0;
	for (int i = 2; i < n; i++)
	{
		temp = second;
		second = sum;
		first = temp;
		first = first % 10;
		second = second % 10;
		sum = first + second;
		sum = sum % 10;
	}
	if (n == 0)
		return first;
	if (n == 1)
		return second;

	return sum;



}

int fibonacci_sum_last_digit_fast_0_n(long long n) {

	int first = 0;
	int second = 1;
	int sum = 1;
	int temp = 0;
	int total = 2;
	for (int i = 2; i < n; i++)
	{
		temp = second;
		second = sum;
		first = temp;
		first = first % 10;
		second = second % 10;
		sum = first + second;
		sum = sum % 10;
		total = (total + sum) % 10;
	}
	if (n == 0)
		return first;
	if (n == 1)
		return second;
	if (n == 2)
		return total;

	return total;

}


long long gcd(long long a, long long b)
{
	int mod;
	if (a != 0 && b == 0)
		return a;
	if (a == 0 && b != 0)
		return b;
	else
	{
		if (a > b)
			gcd(b, a%b);
		else //b>a
			gcd(a, b%a);
	}
}

long long lcm(long long a, long long b)
{
	return (abs(a*b) / gcd(a, b));
}

long long pisano_length(long long m) {

	long long i = 0;

	 int first = 0;
	int second = 1;
	int sum = 1;

	for (i = 0; i < m*m; i++)
	{
		first = first % m;
		second = second % m;
		sum = (first + second) % m;
		
		
		if (sum == 1 && second == 0)
			return i + 1;
		first = second;
		second = sum;
	}


}

long long  last_fib_mod_m(long long n, long long m)
{
	
	long long r = n % pisano_length(m);
	//cout << "remainder " << r;
	//cout << get_fibonacci_last_digit_fast(n)<<"\n";
	return fibonacci_fast_mod_m(r,m);
}



int fibonacci_sum_last_digit_fast_0_log_n(long long n) {
	int number = last_fib_mod_m(n + 2, 10);
	if (number < 1)
		return 9;
	else
		return ((number - 1) % 10);

}

int fibonacci_partial_sum_last_digit_fast_0_log_n(long long m, long long n) {

	if (m <= n)
	{
		int first = last_fib_mod_m(n + 2,10);
		int second = last_fib_mod_m(m + 1,10);
		int diff = first - second;
		if (diff < 0)
			return (10 - abs(diff));
		else
			return abs(diff);
	}
	else
	{
		cout << "error in input";
		return 0;
	}
}




int last_digit_sum_squares(long long n)
{
	int m = 10;
	return ((last_fib_mod_m(n + 1,m)*last_fib_mod_m(n,m)) % 10);
}


void reg_test() {

	int m = 24;
	long long fast = 0;
	long long slow = 0;
	for (int n = 5; n < 40; ++n)
	{
		//cout << n;
		fast = last_digit_sum_squares(n);
		slow = fibonacci_sum_squares_naive(n);
		if (fast != slow)
		{
			cout << "Error";
			cout << fast << "\t";
			cout << slow;
			cout << "\n";
		}
		assert(fast == slow);
		cout << fast << "\t";
		cout << slow ;
		cout << "\n";
	}
}

int main() {
	long long  n = 0;
	long long m = 0;
	std::cin >> n;
	//std::cin>>m>>n;
	//std::cout << "naive :"<<fibonacci_naive(n) << '\n';
	//test_solution();
	//std::cout << fibonacci_fast(n) << '\n';
	//int c = get_fibonacci_last_digit_fast(n);
	//std::cout << fibonacci_sum_last_digit_fast_0_n(n) << "\n";
	//std::cout << fibonacci_sum_last_digit_fast_0_log_n(n)<<"\n";
	//std::cout << fibonacci_partial_sum_last_digit_fast_0_log_n(m, n)<<"\n";
	//std::cout <<c<<'\n';
	//cout << gcd(m,n)<<"\n";
	//cout << lcm(m, n)<<"\n";
	cout << last_digit_sum_squares(n)<<"\n";
	//cout << pisano_length(1000);
	//cout<<last_fib_mod_m(n, m)<<"\n";
	//reg_test();
	system("PAUSE");
	return 0;
}
