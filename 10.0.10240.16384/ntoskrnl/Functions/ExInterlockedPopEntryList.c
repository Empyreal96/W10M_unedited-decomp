// ExInterlockedPopEntryList 
 
_DWORD *__fastcall ExInterlockedPopEntryList(_DWORD **a1, unsigned int *a2)
{
  int v3; // r4
  unsigned int v4; // r2
  _DWORD *result; // r0

  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v3 = 0;
  }
  else
  {
    __disable_irq();
    v3 = 1;
  }
  while ( 1 )
  {
    do
      v4 = __ldrex(a2);
    while ( __strex(1u, a2) );
    __dmb(0xBu);
    if ( !v4 )
      break;
    if ( v3 )
      __enable_irq();
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *a2 );
    __disable_irq();
  }
  result = *a1;
  if ( *a1 )
    *a1 = (_DWORD *)*result;
  __dmb(0xBu);
  *a2 = 0;
  if ( v3 )
    __enable_irq();
  return result;
}
