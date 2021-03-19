#include <string>
#include <iostream>
#include <thread>

using namespace std;

void task1(std::string msg){
	std::cout << "Uma thread com mensagem: " << msg << std::endl;
}

int main(){
	thread t1(task1, "Olá das threads.");

	//.....
	std::cout << "Uma mensagem dentro do main." << std::endl;
	
	t1.join();
}

