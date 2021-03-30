#include <iostream>
#include <string>
#include <curl/curl.h>

//sudo aptitude install libcurl4-openssl-dev
static size_t WriteCallback(char *contents, size_t size, size_t nmemb, char *buffer_in)
{
    ((std::string*)buffer_in)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
  CURL *curl;

  // retorna zero se tudo OK
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.crawlerweb.com.br/template/tmp/js1.php"); 
    
    //Definir retorno de chamada para escrever dados recebidos
    //A função de retorno de chamada receberá o máximo de dados possível em todas as chamadas, mas você não deve fazer suposições. 
    //   Pode ser um byte, pode ser milhares.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); 

    // Informando a variável string que conterá o output
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    // Chame esta função depois que curl_easy_init e todas as chamadas curl_easy_setopt
    // forem feitas e executará a transferência conforme descrito nas opções. 
    res = curl_easy_perform(curl);

    // Esta função deve ser a última função a chamar para uma sessão fácil. É o oposto da função curl_easy_init
    curl_easy_cleanup(curl);

    std::cout << "RES: " << res <<  std::endl << readBuffer << std::endl;
  }
  return 0;
}
