#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

int main () {
   signal(SIGINT, SIG_IGN);  

   while(1) {
      std::cout << "Dentro do laço de repetição infinito." << std::endl;
      sleep(1);
   }

   return 0;
}