#include<iostream>
#include<algorithm>
#include<vector>

#include<boost/lexical_cast.hpp>
#include<boost/iterator/counting_iterator.hpp>

int main(void) {

  std::vector<std::string> fizzbuzz;
  std::transform(boost::counting_iterator<int>(1),
	boost::counting_iterator<int>(100),
	std::back_inserter(fizzbuzz),
	[](const int v) -> std::string {
	  if(v%15 == 0) return "FizzBuzz";
	  if(v%3 == 0) return "Fizz"; 
	  if(v%5 == 0) return "Buzz";
	  return boost::lexical_cast<std::string>(v);
	});
  std::for_each(fizzbuzz.begin(), fizzbuzz.end(),
	[](const std::string s) { std::cout << s << " "; });
  std::cout << std::endl;

  return 0;
}
