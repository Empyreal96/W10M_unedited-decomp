// KiRequestProcessInSwap 
 
unsigned int *__fastcall KiRequestProcessInSwap(int a1, unsigned int *a2)
{
  int v3; // r5
  unsigned int *v4; // r1
  unsigned int v5; // r2
  unsigned int *result; // r0
  unsigned int *v7; // r2
  unsigned int **v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r1
  unsigned int **v11; // r5
  unsigned int *v12; // r1
  unsigned int v13; // r2

  v3 = 0;
  v4 = (unsigned int *)(a1 + 44);
  *(_DWORD *)(a1 + 304) = KeTickCount;
  do
    v5 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v5 )
    return (unsigned int *)sub_50EDB8();
  *(_BYTE *)(a1 + 132) = 9;
  __dmb(0xBu);
  *v4 = 0;
  v7 = (unsigned int *)(a1 + 144);
  v8 = (unsigned int **)a2[20];
  *v7 = (unsigned int)(a2 + 19);
  v7[1] = (unsigned int)v8;
  if ( *v8 != a2 + 19 )
    __fastfail(3u);
  *v8 = v7;
  result = a2 + 29;
  a2[20] = (unsigned int)v7;
  if ( (a2[29] & 7) == 1 )
  {
    __dmb(0xBu);
    do
      v9 = __ldrex(result);
    while ( __strex(v9 ^ 3, result) );
    __dmb(0xBu);
    v3 = 1;
  }
  __dmb(0xBu);
  do
    v10 = __ldrex(a2);
  while ( __strex(v10 & 0xFFFFFF7F, a2) );
  if ( v3 )
  {
    MmNotifyProcessInSwapTrigger(a2);
    v11 = (unsigned int **)(a2 + 21);
    __pld(&KiProcessInSwapListHead);
    result = (unsigned int *)KiProcessInSwapListHead;
    do
    {
      *v11 = result;
      v12 = result;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)&KiProcessInSwapListHead);
      while ( (unsigned int *)v13 == result && __strex((unsigned int)v11, (unsigned int *)&KiProcessInSwapListHead) );
      result = (unsigned int *)v13;
    }
    while ( (unsigned int *)v13 != v12 );
    if ( !v13 )
      result = (unsigned int *)KeSetEvent((int)&KiSwapEvent, 10, 0);
  }
  return result;
}
