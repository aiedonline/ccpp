#include <iostream>
#include <csignal>

using namespace std;

void signal_handler(int signum) {
   std::cout << "Processo será interrompido pelo sinal: (" << signum << ")." << std::endl;
   exit(signum);  
}

int main () {
   int i = 0;
   signal(SIGINT, signal_handler);  

   while(++i) {
      std::cout << "Dentro do laço de repetição infinito." << std::endl;

      if( i == 5 ) {
         raise( SIGINT);
      }

      sleep(1);
   }
   return 0;
}