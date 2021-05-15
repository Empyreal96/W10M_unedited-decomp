// KiBeginThreadAccountingPeriod 
 
int __fastcall KiBeginThreadAccountingPeriod(int result, int a2, unsigned int a3, unsigned int a4)
{
  int v7; // r7
  char v8; // r6
  int v9; // r2
  int v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r3
  unsigned __int64 *v13; // r4
  unsigned __int64 v14; // kr08_8
  unsigned __int64 v15; // kr10_8
  int v16; // r3
  int v17; // r2
  int v18; // r2

  v7 = result;
  if ( !a2 )
    return sub_52C6DC();
  v8 = *(_BYTE *)(a2 + 2);
  if ( (v8 & 0x10) != 0 )
  {
    *(_DWORD *)(result + 2384) = *(_DWORD *)(result + 2376);
    *(_DWORD *)(result + 2388) = *(_DWORD *)(result + 2380);
  }
  if ( (v8 & 0x20) != 0 )
  {
    v9 = *(_DWORD *)(result + 3200);
    v10 = *(_DWORD *)(result + 3204);
    if ( v9 && v10 )
    {
      v11 = *(_DWORD *)(v10 + 44);
      if ( v11 >= *(_DWORD *)(v9 + 148) )
        v11 = *(_DWORD *)(v9 + 148);
    }
    else
    {
      v11 = 100;
    }
    v12 = v11 / 0x19;
    if ( v11 / 0x19 >= 3 )
      v12 = 3;
    v13 = (unsigned __int64 *)(result + 8 * (*(unsigned __int8 *)(result + 2986) + 2 * (v12 + 1144)));
    v14 = *v13 + __PAIR64__(a4, a3);
    __dmb(0xBu);
    do
    {
      v15 = __ldrexd(v13);
      result = v15;
    }
    while ( __strexd(v14, v13) );
    __dmb(0xBu);
  }
  *(_BYTE *)(v7 + 16) = 0;
  if ( (v8 & 0x36) == 0 )
  {
    __enable_irq();
    return result;
  }
  if ( *(_DWORD *)(a2 + 236) )
    result = KiBeginCounterAccumulation(a2, 1);
  __enable_irq();
  if ( (*(_BYTE *)(a2 + 2) & 4) != 0 )
  {
    v16 = *(_DWORD *)(a2 + 80);
    if ( (v16 & 0x400) == 0 )
    {
      if ( (v16 & 0x200) != 0 )
        return result;
      v17 = *(_DWORD *)(a2 + 68);
      if ( !v17 )
        return result;
      v18 = v17 + *(_DWORD *)(v7 + 2352);
      if ( !v18 )
        return result;
      while ( (*(_BYTE *)(v18 + 92) & 2) == 0 )
      {
        v18 = *(_DWORD *)(v18 + 236);
        if ( !v18 )
          return result;
      }
    }
    result = KiInsertDeferredPreemptionApc(v7, a2, 1);
  }
  return result;
}
