// PsSetThreadWin32Thread 
 
unsigned int __fastcall PsSetThreadWin32Thread(int a1, unsigned int a2, int a3)
{
  unsigned int *v4; // r2
  unsigned int result; // r0
  unsigned int v6; // r1

  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 284);
  if ( a2 )
  {
    do
      result = __ldrex(v4);
    while ( __strex(a2, v4) );
  }
  else
  {
    result = 0;
    do
      v6 = __ldrex(v4);
    while ( v6 == a3 && __strex(0, v4) );
  }
  __dmb(0xBu);
  return result;
}
