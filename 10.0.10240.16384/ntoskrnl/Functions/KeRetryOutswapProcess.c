// KeRetryOutswapProcess 
 
int __fastcall KeRetryOutswapProcess(int a1)
{
  int v2; // r6
  unsigned int v3; // r2
  unsigned int *v4; // r0
  int v5; // r5
  unsigned int v6; // r1
  unsigned int v7; // r1
  int result; // r0
  int *v9; // r5
  int v10; // r1
  unsigned int v11; // r2

  v2 = KfRaiseIrql(2);
  do
    v3 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v3 | 0x80, (unsigned __int8 *)a1) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v3 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a1 & 0x80) != 0 );
    do
      v3 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v3 | 0x80, (unsigned __int8 *)a1) );
  }
  v4 = (unsigned int *)(a1 + 116);
  v5 = *(_DWORD *)(a1 + 116) & 7;
  if ( v5 == 1 )
  {
    __dmb(0xBu);
    do
      v6 = __ldrex(v4);
    while ( __strex(v6 ^ 7, v4) );
    __dmb(0xBu);
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)a1);
  while ( __strex(v7 & 0xFFFFFF7F, (unsigned int *)a1) );
  result = KfLowerIrql(v2);
  if ( v5 == 1 )
  {
    v9 = (int *)(a1 + 84);
    __pld(&KiProcessOutSwapListHead);
    result = KiProcessOutSwapListHead;
    do
    {
      *v9 = result;
      v10 = result;
      __dmb(0xBu);
      do
        v11 = __ldrex((unsigned int *)&KiProcessOutSwapListHead);
      while ( v11 == result && __strex((unsigned int)v9, (unsigned int *)&KiProcessOutSwapListHead) );
      result = v11;
    }
    while ( v11 != v10 );
    if ( !v11 )
      result = KeSetEvent((int)&KiSwapEvent, 10, 0);
  }
  return result;
}
