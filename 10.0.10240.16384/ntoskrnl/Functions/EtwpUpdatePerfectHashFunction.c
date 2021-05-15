// EtwpUpdatePerfectHashFunction 
 
unsigned int __fastcall EtwpUpdatePerfectHashFunction(unsigned int *a1, unsigned int *a2, int a3)
{
  unsigned int result; // r0
  unsigned int v5; // r2

  __dmb(0xBu);
  if ( a3 )
  {
    do
      result = __ldrex(a1);
    while ( __strex(0, a1) );
    __dmb(0xBu);
  }
  else
  {
    v5 = *a2;
    do
      result = __ldrex(a1);
    while ( __strex(v5, a1) );
    __dmb(0xBu);
    *a2 = 0;
  }
  return result;
}
