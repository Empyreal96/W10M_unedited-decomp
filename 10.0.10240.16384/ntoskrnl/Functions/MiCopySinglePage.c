// MiCopySinglePage 
 
int __fastcall MiCopySinglePage(int a1, unsigned int a2, int a3, unsigned int a4, unsigned int a5, char a6)
{
  int result; // r0
  int v8; // r5
  int v9; // r6
  unsigned __int8 *v10; // r1
  unsigned int v11; // r2
  int v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r0
  int v15; // r8
  unsigned int v16; // r2
  int v17; // r3
  int v18; // r7
  int v19; // r0
  int v20; // r7
  int v21; // r0
  unsigned int *v22; // r2
  unsigned int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r0
  int v27; // [sp+4h] [bp-2Ch]

  if ( !MI_IS_PFN(a2) )
    return -1073741503;
  v8 = MmPfnDatabase + 24 * a2;
  if ( (a6 & 1) != 0 )
  {
    v9 = KfRaiseIrql(2);
    v10 = (unsigned __int8 *)(v8 + 15);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v11 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
        v12 = *(_DWORD *)(v8 + 12);
        __dmb(0xBu);
      }
      while ( (v12 & 0x80000000) != 0 );
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 | 0x80, v10) );
    }
  }
  else
  {
    v9 = 17;
  }
  if ( !MI_IS_PFN(a2) )
  {
    if ( v9 != 17 )
    {
      __dmb(0xBu);
      v13 = (unsigned int *)(v8 + 12);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 & 0x7FFFFFFF, v13) );
      KfLowerIrql(v9);
    }
    return -1073741503;
  }
  if ( (*(_BYTE *)(v8 + 19) & 0x80) == 128 )
  {
    if ( v9 != 17 )
    {
      __dmb(0xBu);
      v24 = (unsigned int *)(v8 + 12);
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 & 0x7FFFFFFF, v24) );
      KfLowerIrql(v9);
    }
    result = -1073740023;
  }
  else
  {
    v15 = *(unsigned __int8 *)(v8 + 18) >> 6;
    if ( v15 == 3 )
      MiChangePageAttribute(v8, 1, 1);
    v27 = MiMakeProtectionPfnCompatible(1, v8);
    if ( a5 )
    {
      v16 = (MmProtectToPteMask[v27] & 0x3ED | (a2 << 12) | MiDetermineUserGlobalPteMask(a5)) & 0xFFFFF3FF | 0x12;
      if ( a5 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)a5 = v16;
      }
      else
      {
        v17 = *(_DWORD *)a5;
        v18 = 0;
        __dmb(0xBu);
        if ( (v17 & 2) == 0 )
          v18 = 1;
        *(_DWORD *)a5 = v16;
        if ( a5 + 1070596096 <= 0xFFF )
        {
          v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v19, (_DWORD *)(v19 + 4 * (a5 & 0xFFF)), v16);
        }
        if ( v18 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v20 = a5 << 10;
    }
    else
    {
      v20 = MiMapPageInHyperSpaceWorker(a2, 0, -1610612736);
    }
    memmove(a1, v20 + a3, a4);
    if ( a5 )
    {
      if ( a5 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)a5 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)a5 = 0;
        if ( a5 + 1070596096 <= 0xFFF )
        {
          v21 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v21, (_DWORD *)(v21 + 4 * (a5 & 0xFFF)), 0);
        }
      }
    }
    else
    {
      MiUnmapPageInHyperSpaceWorker(v20 + a3, 17, 0x80000000);
    }
    if ( v15 == 3 )
      MiChangePageAttribute(v8, 3, 3);
    if ( v9 != 17 )
    {
      __dmb(0xBu);
      v22 = (unsigned int *)(v8 + 12);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 & 0x7FFFFFFF, v22) );
      KfLowerIrql(v9);
    }
    result = 0;
  }
  return result;
}
