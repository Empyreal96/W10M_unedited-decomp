// KiReadyThread 
 
int __fastcall KiReadyThread(int a1, int a2)
{
  int v3; // r3
  int result; // r0
  int v5; // r0
  unsigned int v6; // r2
  unsigned int *v7; // r4
  unsigned int v8; // r1
  unsigned int v9; // r1
  unsigned __int8 *v10; // r3
  unsigned int v11; // r2
  int *v12; // r4
  int v13; // r1
  unsigned int v14; // r2

  v3 = *(_DWORD *)(a2 + 80);
  if ( (v3 & 0x10000) != 0 )
  {
    if ( (v3 & 0x40000) != 0 )
      result = sub_50A21C();
    else
      result = KiDeferredReadyThread(a1, a2);
  }
  else
  {
    v5 = *(_DWORD *)(a2 + 116);
    do
      v6 = __ldrex((unsigned __int8 *)v5);
    while ( __strex(v6 | 0x80, (unsigned __int8 *)v5) );
    __dmb(0xBu);
    if ( v6 >> 7 )
      JUMPOUT(0x50A2B6);
    v7 = (unsigned int *)(v5 + 116);
    if ( (*(_DWORD *)(v5 + 116) & 7) != 0 )
      JUMPOUT(0x50A2E2);
    __dmb(0xBu);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 + 8, v7) );
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)v5);
    while ( __strex(v9 & 0xFFFFFF7F, (unsigned int *)v5) );
    v10 = (unsigned __int8 *)(a2 + 82);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 & 0xFB, v10) );
    *(_BYTE *)(a2 + 132) = 6;
    v12 = (int *)(a2 + 144);
    __pld(&KiStackInSwapListHead);
    result = KiStackInSwapListHead;
    do
    {
      *v12 = result;
      v13 = result;
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)&KiStackInSwapListHead);
      while ( v14 == result && __strex((unsigned int)v12, (unsigned int *)&KiStackInSwapListHead) );
      result = v14;
    }
    while ( v14 != v13 );
    if ( !v14 )
      result = KeSetEvent(&KiSwapEvent, 10, 0);
  }
  return result;
}
