#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;

void signal_handler(int signum) {
   std::cout << "Processo será interrompido pelo sinal: (" << signum << ")." << std::endl;
   exit(signum);  
}

int main () {
   signal(SIGINT, signal_handler);  

   while(1) {
      std::cout << "Dentro do laço de repetição infinito." << std::endl;
      sleep(1);
   }

   return 0;
}