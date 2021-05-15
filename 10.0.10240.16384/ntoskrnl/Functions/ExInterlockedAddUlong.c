// ExInterlockedAddUlong 
 
int __fastcall ExInterlockedAddUlong(int *a1, int a2, unsigned int *a3)
{
  int v5; // r4
  unsigned int v6; // r2
  int result; // r0

  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v5 = 0;
  }
  else
  {
    __disable_irq();
    v5 = 1;
  }
  while ( 1 )
  {
    do
      v6 = __ldrex(a3);
    while ( __strex(1u, a3) );
    __dmb(0xBu);
    if ( !v6 )
      break;
    if ( v5 )
      __enable_irq();
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *a3 );
    __disable_irq();
  }
  result = *a1;
  *a1 += a2;
  __dmb(0xBu);
  *a3 = 0;
  if ( v5 )
    __enable_irq();
  return result;
}
