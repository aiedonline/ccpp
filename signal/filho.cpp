#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

void signal_parent_handler(int signum) {
   std::cout << "Processo (PAI) será interrompido pelo sinal: (" << signum << ")." << std::endl;
}

void signal_child_handler(int signum) {
   std::cout << "Processo (FILHO) será interrompido pelo sinal: (" << signum << ")." << std::endl;
   sleep(1);
   kill( getppid(), SIGUSR1);
}

int main () {
    pid_t pid;
    pid = fork();

    if(pid < 0) {
   	    std::cout << "Falha!";
   	    exit(0);
    } 
    // Processo filho o PID retornado pelo fork é Zero.
    else if(pid == 0) {
    	signal(SIGUSR1, signal_child_handler);
    	std::cout << "Processo filho aguardando sinal." << std::endl;
    	pause();
    }
    // é o Pai
    else {
    	signal(SIGUSR1, signal_parent_handler);
    	sleep(2);
    	std::cout << "Enviando sinal para o filho." << std::endl;
    	kill(pid, SIGUSR1);
    	std::cout << "Processo pai aguardando resposta." << std::endl;
    	pause();
    }

    return 0;
}