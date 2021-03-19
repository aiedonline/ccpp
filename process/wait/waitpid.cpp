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
  pid_t pid[5];
  int i, stat;

  for (i = 0; i < 5; i++) {
  	pid[i] = fork();
    if( pid[i] == 0) {
      sleep(1);
      exit(100 + i);
    }
  }

  for (i = 0; i < 5; i++) {
    pid_t cpid = waitpid(pid[i], &stat, 0);
    if (WIFEXITED(stat)) {
      std::cout << "O filho " << cpid << " terminou com o status: " << WEXITSTATUS(stat) << std::endl;
    }
  }
  return 0;
}
