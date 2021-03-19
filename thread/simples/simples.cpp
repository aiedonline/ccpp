#include <string>
#include <iostream>
#include <thread>

// Livro gratuito disponível no link: https://docs.google.com/document/d/14S8MAcjspdbBWsja-Ijb_GQfs4C1PzJmDcTJ3bYXyeQ/edit?usp=sharing
// Vídeo explicativo disponível no link: 

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

