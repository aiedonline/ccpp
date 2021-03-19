#include <iostream>

int main()
{
   FILE *fpipe;
   char *command = (char *)"ls -l";
   char line[256];

   if ( !(fpipe = (FILE*)popen(command,"r")) )
   {
      perror("Problems with pipe");
      exit(1);
   }

   while ( fgets( line, sizeof line, fpipe))
   {
      std::cout << "Linha: " << line ;
   }

   pclose(fpipe);
   return 0;
}