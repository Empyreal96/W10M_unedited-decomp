// PopPepGetReadyActivityType 
 
int __fastcall PopPepGetReadyActivityType(int a1, int a2, int a3)
{
  int **v3; // r0
  int *v4; // t1
  int v5; // r3

  if ( a2 > a3 )
    return 6;
  v3 = (int **)(a1 + 4 * a2);
  while ( 1 )
  {
    v4 = *v3++;
    v5 = *v4;
    if ( (*v4 & 2) != 0 || (v5 & 8) != 0 )
      break;
    if ( ++a2 > a3 )
      return 6;
  }
  return a2;
}
