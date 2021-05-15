// ExInterlockedInsertTailList 
 
__int64 **__fastcall ExInterlockedInsertTailList(__int64 *a1, __int64 *a2, unsigned int *a3)
{
  int v5; // r5
  unsigned int v6; // r2
  __int64 **result; // r0
  __int64 v8; // kr00_8

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
  v8 = *a1;
  result = (__int64 **)*((_DWORD *)a1 + 1);
  *(_DWORD *)a2 = a1;
  *((_DWORD *)a2 + 1) = result;
  if ( *result != a1 )
    sub_51B9B4();
  *result = a2;
  *((_DWORD *)a1 + 1) = a2;
  __dmb(0xBu);
  *a3 = 0;
  if ( v5 )
    __enable_irq();
  if ( (__int64 **)v8 == result )
    result = 0;
  return result;
}
