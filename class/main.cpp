#include <iostream>

void someThrowFunction(bool will_throw){
	if(will_throw)
		throw std::logic_error("Throwing from someThrowingFunction\n");
	else
		std::cout << "Didn't throw\n";
	std::cout << "Doing more stuff\n";
}

void someCatchingFunction(int threshold){
	bool will_throw = false;
	if(threshold > 5)
		will_throw = true;
	someThrowFunction(will_throw);
	// try{
	// 	someThrowFunction(will_throw);
	// }
	// catch(std::logic_error err){
	// 	std::cout << "Caught Error in someCatchingFunction\n" << err.what() << std::endl;
	// }

	std::cout<< "someCatchingFunction stuff" << std::endl;
}

int main(){
	// someCatchingFunction(7);
	try{
		someCatchingFunction(7);
	}
	catch(std::logic_error err){
		std::cout << "Caught Error in someCatchingFunction\n" << err.what() << std::endl;
	}
	std::cout << "Main doing more stuff" << std::endl;

	return 0;
}