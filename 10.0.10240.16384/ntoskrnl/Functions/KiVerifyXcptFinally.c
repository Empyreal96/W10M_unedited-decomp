// KiVerifyXcptFinally 
 
int __fastcall KiVerifyXcptFinally(unsigned int **a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r1

  v2 = *a1;
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 + 1, v2) );
  return 0;
}
