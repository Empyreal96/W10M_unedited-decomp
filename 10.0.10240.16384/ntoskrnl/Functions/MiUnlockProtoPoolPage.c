// MiUnlockProtoPoolPage 
 
int __fastcall MiUnlockProtoPoolPage(int a1, int a2)
{
  unsigned __int8 *v3; // r1
  unsigned int v5; // r2
  int result; // r0
  unsigned int *v7; // r2
  unsigned int v8; // r0
  int v9; // r3
  unsigned int v10; // r2

  v3 = (unsigned __int8 *)(a1 + 15);
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 | 0x80, v3) );
  __dmb(0xBu);
  if ( v5 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v9 = *(_DWORD *)(a1 + 12);
        __dmb(0xBu);
      }
      while ( v9 < 0 );
      do
        v10 = __ldrex(v3);
      while ( __strex(v10 | 0x80, v3) );
      __dmb(0xBu);
    }
    while ( v10 >> 7 );
  }
  *(_BYTE *)(a1 + 18) &= 0xDFu;
  if ( MI_REMOVE_LOCKED_PAGE_CHARGE_RETURN_DECREF(a1) )
    return sub_543BE8();
  __dmb(0xBu);
  v7 = (unsigned int *)(a1 + 12);
  if ( a2 == 17 )
  {
    do
      result = __ldrex(v7);
    while ( __strex(result & 0x7FFFFFFF, v7) );
  }
  else
  {
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 & 0x7FFFFFFF, v7) );
    result = KfLowerIrql(a2);
  }
  return result;
}
