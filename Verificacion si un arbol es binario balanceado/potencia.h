
int potencia( int x, int y ) {
  int i = 0;
  int pot = 1;

  while( i < y )
    {  // Abre while
      pot = pot*x;
      i++;
    }  // Cierra while 

  return (pot);
}  /* Cierra potencia*/
