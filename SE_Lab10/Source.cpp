#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>


class  Concate {
public:
	char first[15] = "first part,";
	char second[15] = "second part";

	friend void myfun(Concate obj);
};

void myfun(Concate obj) {
	strcat_s(obj.first, obj.second);
	std::cout << obj.first;
}


auto lambda = [](int x) {
	return (x > 0) ? true : false;
	};


auto check = [](auto val) {
	return std::is_same_v<decltype(val), char >&& val > 0 && val < 128;
	};


auto conct = [](const std::string& one, const std::string& two) {
	return one + two;
	};


auto longerStr = [](const std::string& str1, const std::string& str2) {
	return(str1.length() > str2.length()) ? str1 : str2;
	};


int main() {
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//to find a count of numbers that are equal to entered.
	int target1 = 3;
	int num_items1 = std::count(v.begin(), v.end(), target1);
	std::cout << "the number: " << target1 << " count: " << num_items1 << '\n';
	//lambda expression for counting elements, multiple of 3.
	int num_items3 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	std::cout << " The count of elements, multiple of 3: " << num_items3 << '\n';
	std::cout << std::endl << " Lambda, capture ofvariable" << std::endl;
	//Lambda, capture ofvariable
	for (auto i : v) [i]() {if (i % 3 == 0) std::cout << i << " "; }();

	std::cout << std::endl << " Lambda with parametrs" << std::endl;
	//outputs values that are multiples of 3, the values are passed 
	// as a parameter of the normal function
	for (auto i : v) [](auto i) {if (i % 3 == 0) std::cout << i << " "; }(i);

	std::cout << std::endl << " Lambda without paramets" << std::endl;
	//outputs values that are multiples of 3
	//Values are passed through variable capture, while skipping the parentheses to add parameters
	for (auto i : v) [i] {if (i % 3 == 0) std::cout << i << " "; }();

	int num = 6;
	std::cout << num << (lambda(num) ? "is positive" : "is negative") << std::endl;

	char letter = 'T';
	int integer = 56;
	float fraction = 0.6f;

	std::cout << "char " << letter << " " << check(letter) << std::endl;
	std::cout << "integer " << integer << " " << check(integer) << std::endl;
	std::cout << "float " << fraction << " " << check(fraction) << std::endl;

	std::string result = conct(":", ")");
	std::cout << result << std::endl;

	std::string resLong = longerStr("Hi,", "!");
	std::cout << resLong << std::endl;

	return 0;
}