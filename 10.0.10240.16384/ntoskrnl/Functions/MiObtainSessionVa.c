// MiObtainSessionVa 
 
void __fastcall MiObtainSessionVa(int a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // r3
  int v8; // r6
  int v9; // r9
  int v10; // r5
  int v11; // r0
  int v12; // r1
  int v13; // r0
  char *v14; // r8
  unsigned int v15; // r6
  int v16; // r2
  int v17; // t1
  unsigned int v18; // r1
  unsigned int v19; // r2
  unsigned int v20; // r1
  int v21; // r7
  int *v22; // r7
  int v23; // r4
  int v24; // r1
  unsigned int v25; // r0
  int v26; // r0
  _DWORD *i; // [sp+0h] [bp-30h]
  char var28[44]; // [sp+8h] [bp-28h] BYREF
  int vars4; // [sp+34h] [bp+4h]

  v7 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 0x2000);
  for ( i = v7; ; v7 = i )
  {
    v8 = *v7;
    v9 = 0;
    v10 = 0;
    v11 = KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_6342BC, (unsigned int)var28);
    if ( dword_63529C )
    {
      sub_50FF88(v11, v12, dword_63529C, 10268, a5, a6);
      return;
    }
    v13 = 512 - dword_633884;
    v14 = &byte_63505C[dword_633884];
    v15 = v8 + 4 * dword_633884;
    if ( dword_633884 != 512 )
    {
      while ( 1 )
      {
        v17 = (unsigned __int8)*v14++;
        v16 = v17;
        if ( v17 == 1 && !*(_DWORD *)v15 )
          break;
        if ( !v16 )
          break;
        v9 = 0;
        v10 = 0;
LABEL_8:
        v15 += 4;
        if ( !--v13 )
          goto LABEL_37;
      }
      if ( !v16 )
        ++v10;
      if ( ++v9 != a1 )
        goto LABEL_8;
      if ( v13 )
        break;
    }
LABEL_37:
    if ( dword_633884 )
    {
      dword_633884 = 0;
      KeReleaseInStackQueuedSpinLock((int)var28);
    }
    else
    {
      KeReleaseInStackQueuedSpinLock((int)var28);
      if ( CcUnmapInactiveViews(16 * a1, 1, 0) != 1 )
      {
        ++dword_635260;
        JUMPOUT(0x50FFA2);
      }
    }
  }
  v18 = dword_635310 - (v10 << 22);
  dword_635310 = v18;
  if ( v14 > &byte_63505C[(int)(3072 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2] )
    dword_633890 -= v10 << 22;
  v19 = dword_635024 + v10;
  dword_635024 += v10;
  if ( v18 < dword_633888 )
    dword_633888 = v18;
  if ( v19 > dword_6352D8 )
    dword_6352D8 = v19;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_6342C0);
  }
  else
  {
    do
      v20 = __ldrex((unsigned __int8 *)&dword_6342C0 + 3);
    while ( __strex(v20 | 0x80, (unsigned __int8 *)&dword_6342C0 + 3) );
    __dmb(0xBu);
    if ( v20 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_6342C0);
    while ( 1 )
    {
      v21 = dword_6342C0;
      if ( (dword_6342C0 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_6342C0 & 0x40000000) == 0 )
      {
        v24 = dword_6342C0 | 0x40000000;
        do
          v25 = __ldrex((unsigned int *)&dword_6342C0);
        while ( v25 == v21 && __strex(v24, (unsigned int *)&dword_6342C0) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v9 )
  {
    v22 = &MiState[v14 - byte_63505C];
    v23 = v9;
    do
    {
      --v14;
      --v22;
      if ( *v14 != 1 )
        *v14 = 1;
      ++v22[319];
      if ( v15 < 0xC0000000 || v15 > 0xC03FFFFF )
      {
        *(_DWORD *)v15 = 768;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v15 = 768;
        if ( v15 + 1070596096 <= 0xFFF )
        {
          v26 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v26, (_DWORD *)(v26 + 4 * (v15 & 0xFFF)), 768);
        }
      }
      v15 -= 4;
      --v23;
    }
    while ( v23 );
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_6342C0, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_6342C0 = 0;
  }
  KeReleaseInStackQueuedSpinLock((int)var28);
  MiReclaimSystemVa(0);
}
