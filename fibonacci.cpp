#include <iostream>
#include <vector>

int fibonacci(int count)
{
	
	static std::vector<int> results{ 0, 1 };

	if (count < static_cast<int>(std::size(results))) {
		return results[count];
    }
	else
	{
		results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
		return results[count];
	}
}

int main()
{
	for (int count { 0 }; count < 13; ++count) {
		std::cout << fibonacci(count) << ' ';
    }
	return 0;
}