#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>

// Livro gratuito disponível no link: https://docs.google.com/document/d/14S8MAcjspdbBWsja-Ijb_GQfs4C1PzJmDcTJ3bYXyeQ/edit?usp=sharing
// Vídeo explicativo disponível no link:
// Como compilar acesse o livro ou o vídeo

using namespace std;

int main() {

  // O ID retornado pelo fork() é zero quando o processo filho é criado
  pid_t pID = fork();
  pid_t cpid;
  int stat;

  if ( pID == 0 ) {
  	std::cout << "Saindo do processo filho. " << std::endl;
    exit(1);    
  } else {
    cpid = wait(NULL);
  }

  if (WIFEXITED(stat)){
    std::cout << "WEXIT " << WEXITSTATUS(stat) ;
  } else if (WIFSIGNALED(stat)) {
    psignal(WTERMSIG(stat), "Sinal de saída: ");
  }
  
  std::cout << "PID do pai: " << getpid() << std::endl;
  std::cout << "PID do filho: " << cpid << std::endl;
  return 0;
}