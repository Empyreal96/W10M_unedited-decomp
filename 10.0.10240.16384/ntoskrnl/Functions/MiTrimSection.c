// MiTrimSection 
 
int __fastcall MiTrimSection(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r7
  _DWORD *v5; // r6
  __int64 v6; // r0
  _DWORD *v7; // r8
  unsigned int *v8; // r5
  int v9; // r10
  int result; // r0
  int v11; // r4
  unsigned int v12; // r1
  int v13; // r4
  unsigned int v14; // r1
  unsigned int v15; // r2
  _DWORD *i; // r4
  _DWORD *v17; // r0
  _DWORD *v18; // r4
  _DWORD *v19; // r0
  unsigned int v20; // r1
  unsigned int v21; // r2
  int v23; // [sp+Ch] [bp-3Ch]
  int v24; // [sp+10h] [bp-38h]
  int v25; // [sp+14h] [bp-34h]
  __int64 v26; // [sp+18h] [bp-30h]
  int v27; // [sp+20h] [bp-28h]

  v3 = a1;
  v4 = *(_DWORD *)(a1 + 12);
  v5 = *(_DWORD **)v4;
  v27 = *(_DWORD *)(a1 + 4);
  v25 = v4;
  v6 = MiStartingOffset(v4, v27, -1);
  v23 = HIDWORD(v6);
  v24 = v6;
  v26 = MiStartingOffset(*(_DWORD *)(v3 + 16), *(_DWORD *)(v3 + 8), -1) + 4096;
  v7 = 0;
  MiLockControlAreaFileObjectShared(v5);
  v8 = v5 + 9;
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_511FDC();
  v11 = *v8 & 0x7FFFFFFF;
  do
    v12 = __ldrex(v8);
  while ( v12 == v11 && __strex(v11 + 1, v8) );
  __dmb(0xBu);
  if ( v12 != v11 )
    ExpWaitForSpinLockSharedAndAcquire(v5 + 9, v12);
  v13 = a1;
  if ( v5[5] )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v5 + 9);
    }
    else
    {
      __dmb(0xBu);
      do
        v14 = __ldrex(v8);
      while ( __strex(v14 & 0xBFFFFFFF, v8) );
      __dmb(0xBu);
      do
        v15 = __ldrex(v8);
      while ( __strex(v15 - 1, v8) );
    }
    KfLowerIrql(v9);
    if ( (v5[7] & 0x20) == 0 && v5[8] )
    {
      while ( 1 )
      {
        if ( (*(_WORD *)(v4 + 18) & 8) == 0 )
        {
          v18 = *(_DWORD **)(v4 + 52);
          if ( v18 != (_DWORD *)(v4 + 52) )
          {
            do
            {
              v19 = (_DWORD *)MiViewMayContainPage(v5, v18, v24, v23, v26, HIDWORD(v26));
              if ( v19 )
              {
                *v19 = v7;
                v7 = v19;
              }
              v18 = (_DWORD *)*v18;
            }
            while ( v18 != (_DWORD *)(v4 + 52) );
            v4 = v25;
          }
          v13 = a1;
        }
        if ( v4 == *(_DWORD *)(v13 + 16) )
          break;
        v4 = *(_DWORD *)(v4 + 8);
        v25 = v4;
      }
    }
    for ( i = (_DWORD *)v5[1]; i != v5 + 1; i = (_DWORD *)*i )
    {
      v17 = (_DWORD *)MiViewMayContainPage(v5, i, v24, v23, v26, HIDWORD(v26));
      if ( v17 )
      {
        *v17 = v7;
        v7 = v17;
      }
    }
    MiUnlockControlAreaFileObjectShared(v5);
    result = MiTrimSharedPageFromViews(v7, a2, a3, v5, v27);
  }
  else
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v5 + 9);
    }
    else
    {
      __dmb(0xBu);
      do
        v20 = __ldrex(v8);
      while ( __strex(v20 & 0xBFFFFFFF, v8) );
      __dmb(0xBu);
      do
        v21 = __ldrex(v8);
      while ( __strex(v21 - 1, v8) );
    }
    KfLowerIrql(v9);
    MiUnlockControlAreaFileObjectShared(v5);
    result = 0;
  }
  return result;
}
