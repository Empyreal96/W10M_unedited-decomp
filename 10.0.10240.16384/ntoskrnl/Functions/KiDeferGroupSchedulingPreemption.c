// KiDeferGroupSchedulingPreemption 
 
int __fastcall KiDeferGroupSchedulingPreemption(int a1, int a2)
{
  int v4; // r9
  unsigned int *v5; // r7
  unsigned int v6; // r2
  int v7; // r6
  int v8; // r8
  int v10; // r2
  int v11; // r1
  char v12; // r3
  int v13; // r8
  int v14; // r2
  unsigned int *v15; // lr
  __int64 v16; // r0
  unsigned int v17; // r2
  int v18; // r2
  int v19; // r0
  int v20; // r1
  _DWORD *v21; // r2

  if ( !*(_DWORD *)(a1 + 68) || !*(_DWORD *)(a1 + 308) && *(_BYTE *)(a1 + 134) != 1 )
    return 0;
  v4 = 0;
  v5 = (unsigned int *)(a2 + 24);
  while ( 1 )
  {
    do
      v6 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( !v6 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v5 );
  }
  v7 = *(_DWORD *)(a2 + 8);
  if ( !*(_DWORD *)(a1 + 68)
    || v7 == *(_DWORD *)(a2 + 12)
    || *(unsigned __int8 *)(a2 + 1052) != *(unsigned __int16 *)(a1 + 360)
    || (*(_DWORD *)(a1 + 356) & *(_DWORD *)(a2 + 1048)) == 0
    || ((v8 = *(_DWORD *)(v7 + 68)) == 0
     || (v8 += *(_DWORD *)(a2 + 2352)) == 0
     || (v4 = KiGetThreadEffectiveRankNonZero(*(_DWORD *)(a2 + 8), v8, 1)) == 0)
    && *(char *)(v7 + 123) > *(char *)(a1 + 123) )
  {
    __dmb(0xBu);
    *v5 = 0;
    return 0;
  }
  *(_DWORD *)(a2 + 8) = 0;
  if ( (*(_BYTE *)(a1 + 2) & 4) == 0 )
    return sub_52B664();
  if ( *(char *)(a1 + 123) < 16
    && *(_DWORD *)(a1 + 68)
    && (v10 = *(_DWORD *)(a1 + 68)) != 0
    && (v11 = *(_DWORD *)(a2 + 2352) + v10) != 0
    && KiGetThreadEffectiveRankNonZero(a1, v11, 0) )
  {
    v12 = 1;
  }
  else
  {
    v12 = *(_BYTE *)(a1 + 123);
  }
  **(_BYTE **)(a2 + 28) = v12;
  *(_BYTE *)(v7 + 132) = 1;
  if ( v4 )
  {
    KiAddThreadToScbQueue(a2, v8, v7, 1);
  }
  else
  {
    v13 = *(char *)(v7 + 123);
    v14 = *(_DWORD *)(a2 + 3456);
    if ( (*(_DWORD *)(v7 + 80) & 0x1000) != 0 && v14 && (*(_DWORD *)(v7 + 356) & v14) == v14 )
    {
      v15 = *(unsigned int **)(a2 + 3460);
      HIDWORD(v16) = &v15[2 * v13 + 2];
      while ( 1 )
      {
        do
          v17 = __ldrex(v15);
        while ( __strex(1u, v15) );
        __dmb(0xBu);
        if ( !v17 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v15 );
      }
      LODWORD(v16) = *(_DWORD *)HIDWORD(v16);
      v18 = v7 + 144;
      *(_QWORD *)(v7 + 144) = v16;
      if ( *(_DWORD *)(v16 + 4) != HIDWORD(v16) )
        __fastfail(3u);
      *(_DWORD *)(v16 + 4) = v18;
      *(_DWORD *)HIDWORD(v16) = v18;
      *(_BYTE *)(a2 + (v13 >> 3) + 1936) &= ~(unsigned __int8)(1 << (v13 & 7));
      v15[1] |= 1 << v13;
      *(_DWORD *)(v7 + 328) |= 0x80000000;
      __dmb(0xBu);
      *v15 = 0;
    }
    else
    {
      v19 = *(_DWORD *)(a2 + 8 * (v13 + 256));
      v20 = v7 + 144;
      v21 = (_DWORD *)(a2 + 8 * (v13 + 256));
      *(_DWORD *)(v7 + 144) = v19;
      *(_DWORD *)(v7 + 148) = v21;
      if ( *(_DWORD **)(v19 + 4) != v21 )
        __fastfail(3u);
      *(_DWORD *)(v19 + 4) = v20;
      *v21 = v20;
      *(_BYTE *)(a2 + (v13 >> 3) + 1936) |= 1 << (v13 & 7);
      *(_DWORD *)(a2 + 1932) |= 1 << v13;
    }
  }
  __dmb(0xBu);
  *v5 = 0;
  KiInsertDeferredPreemptionApc(a2, a1, 0);
  return 1;
}
