#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queue>
#include <stack>
#include <complex>

TEST_CASE("1: Queue class")
{
	std::queue<int> queue;
	for (int i = 0; i < 10; i++)
	{
		queue.push(i);
	}
	CHECK(queue.front() == 0);
	CHECK(queue.back() == 9);

	queue.pop();
	CHECK(queue.front() == 1);
}

TEST_CASE("2: Stack class")
{
	std::stack<int> myStack;
	for (int i = 0; i < 10; i++)
	{
		myStack.push(i);
	}
	CHECK(myStack.top() == 9);

	myStack.pop();
	CHECK(myStack.top() == 8);
}

TEST_CASE("3: String class")
{
	std::string str("string test");

	CHECK(str.find("r") == 2);
	CHECK(str.find_last_of("s") == 9);
	CHECK(str.substr(5, 3) == "g t");
}

TEST_CASE("4: Map class")
{
	std::map<int, char> map;
	map.emplace(1, 'a');
	map.emplace(2, 'b');

	CHECK(map[1] == 'a');
	CHECK(map.find(2)->second == 'b');
	CHECK(map.size() == 2);
}

TEST_CASE("5: Complex numbers class")
{
	std::complex<double> myComplex(3.0, 4.0);

	CHECK(std::real(myComplex) == 3.0);
	CHECK(std::imag(myComplex) == 4.0);
	CHECK(std::abs(myComplex) == 5.0);
}

TEST_CASE("6: Merge operation")
{
	int first[] = { 1, 3, 5 };
	int second[] = { 2, 4, 6 };
	int merged[6];

	std::merge(first, first + 3, second, second + 3, merged);
	int answer[] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < 6; i++)
	{
		CHECK(merged[i] == answer[i]);
	}
}

TEST_CASE("7: Sort operation")
{
	int array[] = { 6, 4, 5, 3, 2, 1 };

	std::sort(array, array + 3);
	int half_sorted[] = { 4, 5, 6, 3, 2, 1 };
	for (int i = 0; i < 6; i++)
	{
		CHECK(array[i] == half_sorted[i]);
	}

	std::sort(array, array + 6);
	int sorted[] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < 6; i++)
	{
		CHECK(array[i] == sorted[i]);
	}
}

TEST_CASE("8: Swap operation")
{
	int a = 1, b = 2;
	std::swap(a, b);
	CHECK(b == 1);
	CHECK(a == 2);

	std::string str1 = "test";
	std::string str2;
	std::swap(str1, str2);
	CHECK(str1.empty());
	CHECK(str2 == "test");
}
