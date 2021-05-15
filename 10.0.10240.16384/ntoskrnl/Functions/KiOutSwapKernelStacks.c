// KiOutSwapKernelStacks 
 
int KiOutSwapKernelStacks()
{
  unsigned int v0; // r5
  int v1; // r6
  unsigned int *v2; // r10
  unsigned int v3; // r2
  _DWORD *v4; // r4
  int *v5; // r7
  int v6; // r0
  unsigned int v7; // r3
  int result; // r0
  unsigned __int8 *v9; // r1
  unsigned int v10; // r3
  unsigned int v11; // r2
  __int64 v12; // kr00_8
  _DWORD *v13; // r6
  int v14; // r4
  int v15; // t1
  int v16; // r2
  int v17; // [sp+0h] [bp-40h]
  unsigned int v18; // [sp+4h] [bp-3Ch]
  _DWORD v19[14]; // [sp+8h] [bp-38h] BYREF

  v0 = 0;
  v1 = (int)*(&KiProcessorBlock + KiLastProcessor);
  v18 = KeTickCount - KiStackProtectTime;
  v17 = KfRaiseIrql(2);
  v2 = (unsigned int *)(v1 + 1928);
  while ( 1 )
  {
    do
      v3 = __ldrex(v2);
    while ( __strex(1u, v2) );
    __dmb(0xBu);
    if ( !v3 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v2 );
  }
  v4 = *(_DWORD **)(v1 + 1920);
  if ( v4 != (_DWORD *)(v1 + 1920) )
  {
    v5 = v19;
    do
    {
      if ( v0 >= 5 )
        break;
      v6 = (int)(v4 - 36);
      v7 = v4[40];
      v4 = (_DWORD *)*v4;
      if ( v18 < v7 )
        break;
      if ( *(char *)(v6 + 123) >= 25 )
        return sub_522F04();
      __dmb(0xBu);
      v9 = (unsigned __int8 *)(v6 + 82);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 & 0xFE, v9) );
      __dmb(0xBu);
      do
        v11 = __ldrex(v9);
      while ( __strex(v11 | 4, v9) );
      if ( (unsigned __int8)(v11 & 4) >> 2 )
        *v5 = v6 | 1;
      else
        *v5 = v6;
      v12 = *(_QWORD *)(v6 + 144);
      ++v0;
      ++v5;
      if ( *(_DWORD *)(v12 + 4) != v6 + 144 || *(_DWORD *)HIDWORD(v12) != v6 + 144 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v12) = v12;
      *(_DWORD *)(v12 + 4) = HIDWORD(v12);
      __dmb(0xBu);
      *(_DWORD *)(v6 + 436) = 0;
    }
    while ( v4 != (_DWORD *)(v1 + 1920) );
  }
  __dmb(0xBu);
  *v2 = 0;
  result = KfLowerIrql(v17);
  if ( ++KiLastProcessor == KeNumberProcessors_0 )
    KiLastProcessor = 0;
  if ( v0 )
  {
    v13 = &v19[v0];
    do
    {
      v15 = *--v13;
      v14 = v15;
      --v0;
      if ( (v15 & 1) != 0 )
        v14 &= 0xFFFFFFFE;
      KiWaitForContextSwap(v14);
      if ( v16 )
        KiDecrementProcessStackCount(*(_DWORD *)(v14 + 116));
      result = MmOutPageKernelStack(v14);
    }
    while ( v0 );
  }
  return result;
}
