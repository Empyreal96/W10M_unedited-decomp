// MiConfirmPageIsZero 
 
int __fastcall MiConfirmPageIsZero(unsigned int a1, char a2)
{
  _DWORD *v2; // r6
  int v3; // r0
  _DWORD *v4; // r4
  _DWORD *v5; // r5
  int v7; // r2
  int v8; // r4
  int v9; // r0
  unsigned int v10; // r5
  int v11; // r3
  int v12; // r6
  int v13; // r0
  int v14; // r6
  unsigned int v15; // r5
  unsigned __int8 *v16; // r1
  unsigned int v17; // r2
  unsigned int *v18; // r2
  unsigned int v19; // r0
  int v20; // r0
  int v21; // r3
  int v22; // r7
  int v23; // r0
  int v24; // r3
  unsigned int v25; // r2

  v2 = (_DWORD *)a1;
  if ( (*(_DWORD *)(a1 + 12) & 0x3FFFFFFF) != 1 || *(_WORD *)(a1 + 16) != 1 )
    return 0;
  if ( (a2 & 2) == 0 )
  {
    v3 = MiMapPageInHyperSpaceWorker((int)(a1 - MmPfnDatabase) / 24, 0, 0x80000000);
    v4 = (_DWORD *)v3;
    v5 = (_DWORD *)(v3 + 4092);
    do
    {
      if ( *v4 | *v5 )
        break;
      ++v4;
      --v5;
    }
    while ( v4 <= v5 );
    a1 = MiUnmapPageInHyperSpaceWorker(v3, 17, 0x80000000);
    if ( v4 <= v5 )
      return 0;
  }
  v7 = v2[2];
  if ( (v7 & 8) != 0 )
    return sub_53ACD0(a1);
  v8 = v2[2] & 0x3E0;
  if ( (v7 & 2) == 0 && (v7 & 0xC00) == 0 && (v7 & 0x18) == 0 && (v7 & 0xFFFFE000) == 0x2000 )
    v8 = v2[2] & 0x3E0 | 0x2000;
  v9 = v2[5];
  v10 = v2[1] | 0x80000000;
  if ( (v9 & 0x8000000) != 0 )
  {
    v13 = v9 & 0xFFFFF;
    v14 = MmPfnDatabase + 24 * v13;
    v15 = MiMapPageInHyperSpaceWorker(v13, 0, 0x80000000) + 4 * ((v10 >> 2) & 0x3FF);
    if ( v15 < 0xC0000000 || v15 > 0xC03FFFFF )
    {
      *(_DWORD *)v15 = v8;
    }
    else
    {
      v21 = *(_DWORD *)v15;
      v22 = 0;
      __dmb(0xBu);
      *(_DWORD *)v15 = v8;
      if ( (v21 & 2) == 0 && (v8 & 2) != 0 )
        v22 = 1;
      if ( v15 + 1070596096 <= 0xFFF )
      {
        v23 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v23, (_DWORD *)(v23 + 4 * (v15 & 0xFFF)), v8);
      }
      if ( v22 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    MiUnmapPageInHyperSpaceWorker(v15, 17, 0x80000000);
    v16 = (unsigned __int8 *)(v14 + 15);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 | 0x80, v16) );
    __dmb(0xBu);
    if ( v17 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v24 = *(_DWORD *)(v14 + 12);
          __dmb(0xBu);
        }
        while ( (v24 & 0x80000000) != 0 );
        do
          v25 = __ldrex(v16);
        while ( __strex(v25 | 0x80, v16) );
        __dmb(0xBu);
      }
      while ( v25 >> 7 );
    }
    if ( (*(_BYTE *)(v14 + 18) & 7) != 6 )
      KeBugCheckEx(78, 153, (v14 - MmPfnDatabase) / 24);
    if ( !MiUpdateShareCount(v14, -1) )
      MiPfnShareCountIsZero(v14, 0);
    __dmb(0xBu);
    v18 = (unsigned int *)(v14 + 12);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 & 0x7FFFFFFF, v18) );
  }
  else if ( v10 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v10 = v8;
  }
  else
  {
    v11 = *(_DWORD *)v10;
    v12 = 0;
    __dmb(0xBu);
    *(_DWORD *)v10 = v8;
    if ( (v11 & 2) == 0 && (v8 & 2) != 0 )
      v12 = 1;
    if ( v10 >= 0xC0300000 && v10 <= 0xC0300FFF )
    {
      v20 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v20, (_DWORD *)(v20 + 4 * (v10 & 0xFFF)), v8);
    }
    if ( v12 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  return 1;
}
