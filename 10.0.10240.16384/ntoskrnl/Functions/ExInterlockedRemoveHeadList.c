// ExInterlockedRemoveHeadList 
 
_DWORD *__fastcall ExInterlockedRemoveHeadList(_DWORD *a1, unsigned int *a2)
{
  _DWORD *v2; // r4
  int v3; // r5
  unsigned int v4; // r2
  _DWORD *v5; // r2
  __int64 v7; // kr00_8

  v2 = 0;
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
  v5 = (_DWORD *)*a1;
  if ( (_DWORD *)*a1 != a1 )
  {
    v7 = *(_QWORD *)v5;
    if ( (_DWORD *)v5[1] != a1 || *(_DWORD **)(v7 + 4) != v5 )
      sub_51B9B4();
    *a1 = v7;
    *(_DWORD *)(v7 + 4) = a1;
    v2 = v5;
  }
  __dmb(0xBu);
  *a2 = 0;
  if ( v3 )
    __enable_irq();
  return v2;
}
