#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  ssize_t bytes_leidos;
  size_t numero_bytes;
  //ssize_t y size_t son sinónimos de unsigned int
  char *stringg;

  printf("$ ");
  /* pasas a getline los argumentos inicializados:
   * numero_bytes = tamaño del texto que escribis después del $
   * stringg = (char *) malloc (numero_bytes + 1)
   * *poner numero_bytes a 0 y stringg a NULL, para que él mismo te haga
  la reserva necesaria*/
  numero_bytes = 0;
  stringg = NULL;
  bytes_leidos = getline(&stringg, &numero_bytes, stdin);

  if (bytes_leidos == -1)
    printf("Error.");
  else
    printf("%s", stringg);
  free(stringg);

  return 0;
}
