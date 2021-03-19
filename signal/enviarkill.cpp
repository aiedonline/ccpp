#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;

void signal_handler(int signum) {
   std::cout << "Processo será interrompido pelo sinal: (" << signum << ")." << std::endl;
   exit(signum);  
}

int main () {
   int pid, i = 0;
   signal(SIGINT, signal_handler);  

   while(++i) {
      std::cout << "Dentro do laço de repetição infinito." << std::endl;

      if( i == 5 ) {
         pid = getpid();
         kill(pid, SIGUSR1);
         std::cout << "Tudo tem um fim, mas isso não será exposto, kkkk" << std::endl;
      }

      sleep(1);
   }
   return 0;
}