// qualquer tecla menos o <enter> alterará a direção do contador
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
  int contador = 0;
  char* direcao = "";
  bool sobe_desce = true;
  char str[1];
  memset(str, 0, sizeof(str));
  str[strlen(str)] = true;
  while (1)
  {
    char tecla = 0;
    tecla = getchar();
    if (tecla != 0xff)
    {
       sobe_desce = !sobe_desce;
       str[strlen(str)] = sobe_desce;
    }    
    if (str[strlen(str)] == true)
      {
        direcao = "crescente";
        contador++;
      }
    if (str[strlen(str)] == false)
      {
        direcao = "decrescente";
        contador--;
      }
      printf("\nDireção do contador: %s\n", direcao);
      printf("Contagem: %d\n", contador);
      vTaskDelay(200 / portTICK_PERIOD_MS);
  }
} 
